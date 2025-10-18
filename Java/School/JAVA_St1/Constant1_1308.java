import java.util.*;
public class Constant1_1308 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		
		System.out.print ( "정수 입력 : " );
		int nu = sca.nextInt();

		System.out.printf ( "%d의 절대값은 %d입니다.", nu, nu*(-1) );
	}
}