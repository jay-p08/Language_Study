import java.util.*;
public class Sum_Odd_Even {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "�� �Է� : " );
		int num = sc.nextInt();
		System.out.print ( "Ȧ�� = 1, ¦�� = 2  \n�޴� �Է� : " );
		int menu = sc.nextInt();
		int even, odd;
		if ( menu == 1 ) {
			odd = Sum_Odd ( num );
		} else if ( menu == 2 ) {
			even = Sum_Even ( num );
		}
	}
	static int Sum_Odd ( int num ) {
		int odd = 0;
		for ( int i = 1 ; i <= num ; i++ ) 
			if ( i%2 == 1 ) odd += i;
		System.out.printf ( "Ȧ�� : %d", odd );
		return odd;
	}
	static int Sum_Even ( int num ) {
		int even = 0;
		for ( int i = 1 ; i <= num ; i++ )
			if ( i%2 == 0 ) even += i;
		System.out.printf ( "¦�� : %d", even );
		return even;
	}
	
}