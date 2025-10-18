import java.util.*;
public class MinOfTheree {
	public static void main ( String [ ] args )  {
		int num1 = sca ( "첫 " );
		int num2 = sca ( "두 " );
		int num3 = sca ( "세 " );
		
		int res = Ash ( num1, num2, num3 );
			System.out.printf ( "%d와 %d와 %d 중 제일 작은 수는 %d입니다.", num1, num2, num3, res );
	}
	static int Ash( int a, int b, int c ) { //return 타입
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
		System.out.printf ( "%s번째 수 입력 : ", k );
		return sca.nextInt();
	}
}