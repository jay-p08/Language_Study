import java.util.*;
public class Cond_Op {
	public static void main ( String [ ] arg ) {
		Scanner sc = new Scanner ( System.in );
		
		System.out.printf ( "정수 입력 : " );
		int num = sc.nextInt();
		int sum = num%2;

		
		char string = ( num%2 == 0 ) ? '짝' : '홀' ;
		System.out.printf ( "%d은(는) %s수입니다.", num, string );
	}
}