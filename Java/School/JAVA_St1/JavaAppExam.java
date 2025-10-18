// 최초 작성자 : 박재영
import java.util.*;
public class JavaAppExam {
	public static void main( String[ ] args ) {
		Scanner sca = new Scanner ( System.in );
		
		System.out.print ( "정수 입력 : " );
		int num = sca.nextInt();

		for ( int a = 1 ; a <= num ; a ++ ) {
			for ( int b = 1 ; b <= a ; b ++ )
				System.out.print ( "*" + "\t");
				System.out.print ( "\n" );
		}
		for ( int c = (num-1) ; c >= 1 ; c -- ) {
			for ( int d = 1 ; d <= c ; d ++ )
				System.out.print ( "*" + "\t");
				System.out.print ( "\n" );
		}
	}
}