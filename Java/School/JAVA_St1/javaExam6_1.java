import java.util.*;
public class javaExam6_1 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		int j = 1;
		for ( int i = 1 ; i <= 5 ; i++ ) {
			for ( j = 1 ; j <= 5-i ; j++ )
				System.out.printf ( "* " );
			for ( int l = 1 ; l <= i ; l++ )
				System.out.printf ( "%d ", l );
			System.out.print ("\n");
		}
	}
}