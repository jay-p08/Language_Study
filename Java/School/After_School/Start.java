import java.util.Scanner;

public class Start {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        int star = sc.nextInt();
        char ch = 'a';
        for( int i = 0 ; i < star ; i++ ) {
            for( int j = 0 ; j <= i ; j++ ) {
                System.out.print((char)(ch+j));
            }
            System.out.println();
        }
        for( int i = star ; i > 0 ; i-- ) {
            for( int j = 0 ; j < i ; j++ ) {
                System.out.print((char)(ch+j));
            }
            System.out.println();
        }
        sc.close();
    }
}
