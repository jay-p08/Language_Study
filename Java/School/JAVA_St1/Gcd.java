import java.util.*;
public class Divisor {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "숫자1 입력 :  " );
		int start = sc.nextInt();
		System.out.print ( "숫자2 입력 :  " );
		int end = sc.nextInt();
		if ( start < end ) {
			int a = start;
			start = end;
			end = a;
		}
		for ( int i = end ; i <= start ;  ) {
			int sum = start-end;
			if ( sum == end ) {
				System.out.printf ( "%d", sum ); break;
			}
			else start = sum;
		}
	}
}