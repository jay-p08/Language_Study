import java.util.*;
public class ForExam7_1 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		int num = sca.nextInt();
		int k = 1;
		for ( int i = 1 ; i <= 5 ; i++ ) {
			for ( int j = 1 ; j <= (num+1)-i ; j++ )
				System.out.printf ( "%02d  ", k++ );
			System.out.print ("\n");
		}
	}
}