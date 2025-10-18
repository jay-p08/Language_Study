import java.util.*;
public class GugudanArry {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "시작 단 입력 : " );
		int a = sca.nextInt();
		int[] end = new int[9];
		int[] start = new int[a-1];
		for ( int i = 0 ; i < start.length ; i++ ) 
			start[i] = (i+2);
		for ( int i = 0 ; i < end.length ; i++ ) 
			end[i] = (i+1);
		for ( int i = 0 ; i < start.length ; i++ ) {
			for ( int j = 0 ; j < end.length ; j++ )
				System.out.printf ( "%d * %d = %d\n", start[i], end[j], start[i]*end[j] );
			System.out.println();
		}
	}
}