import java.util.*;
public class For_Test6 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "문자 입력 ==> " );
		char ch = sc.next().charAt(0);
		for ( int i = 65 ; i <= ch ; i++ ) {
			for ( char j = 'A' ; j <= i ; j++)
				System.out.printf ("%c", (char)i );
			System.out.println ();
		}
	}
}