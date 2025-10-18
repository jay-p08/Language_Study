import java.util.*;
public class WhileOdd1to100 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "Á¤¼ö" );
		int i = 1, num = 0;
		while ( i <= 100 ) {
			if ( i%2 == 1 )
				System.out.printf ( "%d\n", i);
			i++;
		}
	}
}