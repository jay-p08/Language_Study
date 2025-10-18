import java.util.*;
public class getMax {
	public static void main ( String [ ] args )  {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "첫 번째 수 입력 : " );
		int num = sca.nextInt();
		System.out.print ( "두 번째 수 입력 : " );
		int num1 = sca.nextInt();
		System.out.print ( "세 번째 수 입력 : " );
		int num2 = sca.nextInt();
		
		if ( num < num1 && num < num2 )
			System.out.printf ( "%d와 %d와 %d 중 제일 작은 수는 %d입니다.", num, num1, num2, num );
		else if ( num1 < num && num1 < num2 )
			System.out.printf ( "%d와 %d와 %d 중 제일 작은 수는 %d입니다.", num, num1, num2, num1);
		else 
			System. out.printf ( "%d와 %d와 %d 중 제일 작은 수는 %d입니다.", num, num1, num2, num2);
	}
}