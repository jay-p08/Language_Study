import java.util.Scanner;

public class Continue {
    public static void main( String[] args ) {
        Scanner sc = new Scanner( System.in );
        int num = 0;

        for( int i = 0 ; i < 5 ; i++ ) {
            int temp = sc.nextInt();
            if( temp < 0 ) continue;
            else num += temp;
        }
        System.out.println(num);

        sc.close();
    }
}
