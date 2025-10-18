import java.util.*;
public class Star_03 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		int j = 1;
		for ( int i = 5 ; i >= 1 ; i-- ) {
			for ( j = 1 ; j <= i ; j++ )
				System.out.print ( "*" );
			System.out.print ("\n ");
		}
	}
}