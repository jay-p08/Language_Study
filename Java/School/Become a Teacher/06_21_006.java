import java.util.*;
public class java004 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "�ֹε�Ϲ�ȣ�� �Է��ϼ��� ( -���� �Է� ) : " );
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