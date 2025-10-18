import java.util.*;
public class ForExam4 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		int num = sca.nextInt();
		for ( int i = 1 ; i <= 5 ; i++ ) {
			for ( int j = 1 ; j <= 5 ; j++) {
				System.out.printf ( "%d ", j );
			} System.out.print ("\n");
		}
	}
}