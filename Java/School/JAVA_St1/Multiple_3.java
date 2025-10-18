import java.util.*;
public class Multiple_3 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		
		System.out.print ( "정수 입력 : " );
		int nu = sca.nextInt();
		if ( nu%3 == 0 ) {
			System.out.printf ( "%d은(는) 3의 배수입니다.", nu );
		}
	}
}