import java.util.*;
public class Divisor {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "���� �Է� :  " );
		int div = sc.nextInt();
		for ( int i = 1 ; i <= div ; i++ )
			if ( div%i == 0 )
				System.out.printf ( "%d \t",i );
	}
}