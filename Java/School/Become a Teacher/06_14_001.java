import java.util.*;
public class score {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "문장 입력 : " );
		String str = sca.next();
		char[] ch1 = new char[str.length()];
		char[] ch2 = new char[str.length()];
		for ( int i = 0 ; i < str.length() ; i++ ) ch1[i] = str.charAt(i);
		for ( int i = 0, j = str.length()-1 ; i < str.length() ; i++, j-- ) {
			ch2[i] = ch1[j];
			if ( ch2[i] >= 'A' && ch2[i] <= 'Z' ) ch2[i] += 32;
			else ch2[i] -= 32;
		}
		for ( int i = 0 ; i < str.length() ; i++ )
			System.out.printf ( "%c", ch2[i] );
	}
}