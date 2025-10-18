import java.util.*;
public class ForExam5_1 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		for ( int i = 5 ; i >= 1 ; i-- ) {
			for ( int j = 1; j <= i ; j++) {
				System.out.printf ( "%d ", j );
			} System.out.print ("\n");
		}
	}
}