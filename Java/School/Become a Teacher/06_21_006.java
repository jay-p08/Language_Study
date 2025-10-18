import java.util.*;
public class java004 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "주민등록번호를 입력하세요 ( -까지 입력 ) : " );
		String str = sc.next();
		char[] ch = new char[str.length()];
		for ( int i = 0 ; i < 8 ; i++ )
			ch[i] = str.charAt(i);
		for ( int i = 8 ; i < ch.length ; i++ )
			ch[i] = '*';
		for ( int i = 0 ; i < ch.length ; i++ )
			System.out.printf ( "%c", ch[i] );
	}
}