import java.util.*;
public class ForExam5 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		for ( int i = 1 ; i <= 5 ; i++ ) {
			for ( int j = 1 ; j <= i ; j++) {
				System.out.printf ( "%d ", j );
			} System.out.print ("\n");
		}
	}
}