package exceptionTest2;

import java.util.Scanner;

public class Chatting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String message = null;

        System.out.println("채팅 : ");
        message = sc.nextLine();

        if (message.contains("바보")) {
            try {
                throw new BadWordException("비속어 사용");
            } catch (Exception e) {
                System.out.println("비속어 사용");
            }
        } else {
            System.out.println(message);
        }
    }
}
