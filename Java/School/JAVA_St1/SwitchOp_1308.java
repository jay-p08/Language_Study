
import java.util.*;
public class SwitchOp_1308 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "수 입력 : " );
		int number = sc.nextInt();
		if ( number%3 == 0 ) {
			System.out.printf ( "%d은 3의 배수이다.\n", number );
		} else if ( number%5 == 0 ) {
			System.out.printf ( "%d은 5의 배수이다.\n", number );
		} else if ( number%8 == 0 ) {
			System.out.printf ( "%d은 8의 배수이다.\n", number );
		} else {
			System.out.print ( "어느 배수도 아니다." );
		}
	}
}