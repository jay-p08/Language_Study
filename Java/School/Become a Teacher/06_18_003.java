import java.util.*;
public class java003 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "�л� �� �Է� : " );
		int sco = sca.nextInt();
		int[] num1 = new int[sco];
		int[] num2 = new int[sco];
		for ( int i = 0 ; i < num1.length ; i++ ) {
			System.out.printf ( "%d���� ���� �Է� : ", i+1 );
			num1[i] = sca.nextInt();
			num2[i] = num1[i]*3;
			if ( num2[i]%2 == 0 ) num2[i] -= 1 ;
			else num2[i] += 1;
		}
		for ( int i = 0 ; i < num1.length ; i++ )
			System.out.printf ( "%d ", num2[i] );
	}
}