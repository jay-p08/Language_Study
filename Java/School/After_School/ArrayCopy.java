import java.util.Scanner;

public class ArrayCopy {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        String age = "010203-3123411";

        if( age.charAt(7) == '1' || age.charAt(7) == '3' ) System.out.println( "남자" );
        else if( age.charAt(7) == '2' || age.charAt(7) == '4' ) System.out.println( "여자" );
        else System.out.println( "잘못된 주민정보" );

        sc.close();
    }
}