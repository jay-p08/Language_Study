import java.util.*;
public class java004 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		String[] str = new String[]{"���", "�Ķ��̵�", "����"};
		int cnt = 0;
		System.out.print ( "ġŲ ���� : " );
		String st = sc.next();
		for ( int i = 0 ; i < str.length ; i++ ) {
			switch ( str[i] ) {
				case "����" : ;
				case "�Ķ��̵�" : ;
				case "���" : System.out.printf ( "%sġŲ ��� ����.", st ); break;
				default : System.out.printf ( "%sġŲ ��� �Ұ�.", st ); break;
			} break;
		}
	}
}