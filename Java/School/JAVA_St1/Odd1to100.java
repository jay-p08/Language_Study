import java.util.*;
public class Odd1to100 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		int num = sc.nextInt();
		int i = 1;
		int snm = 0;
		for ( i = 1 ; i <= num ; i++ ) {
			if ( i%2 == 1 ) {
				if ( i == 1 ) System.out.print ( "1" );
				else System.out.printf ( " + %d", i );
			} else System.out.printf ( " - %d", i );
			sum = sum+i*flag;
			flag = flag*-1;
		}
		System.out.printf ( "= %d\n", snm);
	}
}