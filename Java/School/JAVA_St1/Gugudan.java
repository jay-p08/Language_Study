import java.util.*;
public class Gugudan {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "시작 단 입력 : " );
		int startDan = sca.nextInt();
		System.out.print ( "마지막 단 입력 : " );
		int endDan = sca.nextInt();
		Gugu_Dan ( startDan, endDan );
	}
	static void Gugu_Dan ( int startDan, int endDan ) {
		int a = 0;
		if ( endDan <= startDan ) {
			a = startDan;
			startDan = endDan;
			endDan = a;
		}
		for ( int i = 1 ; i <= 9 ; i++ ) {
			for ( int j = startDan ; j <= endDan ; j++ )
				System.out.printf ( "%d * %d = %d\t", j, i, j*i );
			System.out.print ( "\n" );
		}
			
	}
}