import java.util.*;
public class MinOfTheree {
	public static void main ( String [ ] args )  {
		int num1 = sca ( "ù " );
		int num2 = sca ( "�� " );
		int num3 = sca ( "�� " );
		
		int res = Ash ( num1, num2, num3 );
			System.out.printf ( "%d�� %d�� %d �� ���� ���� ���� %d�Դϴ�.", num1, num2, num3, res );
	}
	static int Ash( int a, int b, int c ) { //return Ÿ��
		int result;
		if ( a < b ) 
			else if ( b < c )
				result = a;
		if ( b < a )
			else if ( b < c )
				result = b;
		if ( c < a )
			else if ( c < b )
				result = c;
		return result;
	}
	static int sca ( String k ) {
		Scanner sca = new Scanner ( System.in );
		System.out.printf ( "%s��° �� �Է� : ", k );
		return sca.nextInt();
	}
}