import java.util.Scanner;

public class Mean {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );

        int Input = 0;
        float sum = 0;

        int cnt = 1;

        while ( true ) {
            System.out.print( "정수 입력 ( -1입력시 종료 ) : " );
            Input = sc.nextInt();
            if ( Input == -1) {
                break;
            }
            sum += Input;
            cnt++;
        }

        System.out.printf( "\n평균 : %.2f\n", ( sum/cnt ) );
    }
}
