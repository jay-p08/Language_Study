import java.util.*;
public class java004 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		int num = 0;
		int cnt = 0;
		do {
			System.out.print ( "정수 입력 : " );
			num = sc.nextInt();
			if ( num < 3 || num%2 == 0 ) 
				System.out.print ( "다시 입력.\n" );
			else break;
		} while ( true );
		int[] arry = new int[num];
		for ( int i = 0 ; i < arry.length ; i++ ) {
			if ( i <= arry.length/2 ) arry[i] = ++cnt;
			else arry[i] = --cnt;
		}
		for ( int i = 0 ; i < arry.length ; i++ )
			System.out.printf ( "%d ", arry[i] );
	}
}