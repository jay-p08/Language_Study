import java.util.*;
public class Prime {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "정수 입력 : " );
		int start = sca.nextInt();
		int cut = 0;
		for ( int i = 2 ; i <= start ; i++  ) {
			if ( start%i == 0 && start != i ) {
				System.out.printf ( "%d는 소수가 아닙니다.", start ); break;
			}
			else if ( start%i == 0 && start == i ) {
				System.out.printf ( "%d는 소수입니다.", start ); break;
			}
			if ( cut%10 == 0 ) System.out.println ();
			cut++;
		}
	}
}