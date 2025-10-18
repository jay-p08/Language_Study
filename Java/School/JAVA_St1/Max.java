import java.util.*;
public class Max {
	public static void main ( String [ ] args )  {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "첫 번째 수 입력 : " );
		int num = sca.nextInt();
		System.out.print ( "두 번째 수 입력 : " );
		int num1 = sca.nextInt();
		
		if ( num > num1 ) {
			System.out.printf ( "%d와 %d 중 큰 수는 %d입니다.", num, num1, num );
		} else {
			System.out.printf ( "%d와 %d 중 큰 수는 %d입니다.", num, num1, num1 );
		}
	}
}