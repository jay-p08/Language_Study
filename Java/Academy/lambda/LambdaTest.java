package lambda;

public class LambdaTest {
    public static void main(String[] args) {
        /*LambdaInter lambdaInter1 = new LambdaInter() {
            @Override
            public boolean checkMultipleOf10(int number) {
                return false;
            }
        };*/

        LambdaInter lambdaInter1 = (number -> number % 10 == 0);
        boolean result = lambdaInter1.checkMultipleOf10(59);
        System.out.println(result);

        LambdaInter lambdaInter2 = (n) -> {
            System.out.println("10의 배수 검사");
            return n % 10 == 0;
        };

        boolean result2 = lambdaInter2.checkMultipleOf10(70);
        System.out.println(result2);
    }
}
