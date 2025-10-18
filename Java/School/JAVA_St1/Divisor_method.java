import java.util.*;
public class Divisor_method {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "숫자 입력 :  " );
		int div = sc.nextInt();
		Divisor_Method ( div );
	}
	static void Divisor_Method ( int div ) {
		for ( int i = 1 ; i <= div ; i++ )
			if ( div%i == 0 )
				System.out.printf ( "%d \t",i );
	}
}