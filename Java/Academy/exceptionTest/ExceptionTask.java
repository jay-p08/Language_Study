package exceptionTest;

import java.util.Scanner;

public class ExceptionTask {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] number = new int[5];
        String str = null;
        int j = 0;
        do {
            str = sc.next();

            if (str.equals("q")) {
                for (int i = 0 ; i < number.length ; i++ ) {
                    System.out.println(number[i]);
                } break;
            }
            try {
                number[j] = Integer.parseInt(str);
            } catch (NumberFormatException e) {
                System.out.println("정수만 입력 하세요");
                j--;
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("이미 5개의 정수를 입력 했습니다.\n프로그램을 종료합니다.");
                for (int i = 0 ; i < number.length ; i++ ) {
                    System.out.println(number[i]);
                } break;
            } catch (Exception e) {
                System.out.println("알 수 없는 오류");
                System.out.println(e);
                j--;
            }
            j++;
        } while (true);
    }
}