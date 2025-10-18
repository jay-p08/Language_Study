package exceptionTest;

public class ExceptionTest {
    public static void main(String[] args) {
        /*try {
            System.out.println(10 / 0);
        } catch (ArithmeticException e) {
            System.out.println("0으로 나눌 수 없습니다.");
        }*/

        /*try {
            System.out.println(10/0);
        } catch (Exception e) {
            System.out.println("알 수 없는 오류가 발생");
            System.out.println(e);
        }*/

        /*try {
            System.out.println(10/0);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("배열의 인덱스를 확인 하세요");
        }
            System.out.println("반드시 실행해야 하는 문장");*/


        try {
            System.out.println(10/0);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("배열 인덱스 확인");
        } finally {
            System.out.println("반드시 실행 문장");
        }
    }
}
