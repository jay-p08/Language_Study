import java.util.*;
import static java.lang.System.out;
public class date {
	public static void main ( String [] args ) {
		String[] date = new String[]{"�ǽù�", "�籸��", "��ũ���߱���", "�ｺ��", "����ڹ���"};
		int bun[] = new int [5];
		int b[] = new int[5];
		int hour = 5;
		int min = 0;
		String[] a = new String[5];
		for ( int i = 0 ; i < date.length ; i++ ) {
			int random = (int)(Math.random() * 59 + 0 );
			bun[i] = random;
			a[i] = date[i];
		}
		for ( int i = 0 ; i < date.length ; i++ ) {
			int random = (int)(Math.random() * 5 + 1 );
			b[i] = random-1;
			for ( int j = 0 ; j < i ; j++ )
				if ( b[i] == b[j] ) {
					i--; break;
				}
		}
		for ( int i = 0 ; i < date.length ; i++ )
			date[i] = a[b[i]];
		out.printf ( "\nö���� ���� ������ ����Ʈ �ڽ�\n������� ����Ʈ �ڽ��� : %s ", date[0] );
		for ( int i = 1 ; i < date.length ; i++ )
			out.printf ( "-> %s ", date[i] );
		for ( int i = 0 ; i < date.length ; i++ )
			min += bun[i];
		for ( int i = 0 ; i < date.length ; i++ ) 
			if ( min > 60 ) {
				min -= 60;
				hour += 1;
			}
		out.printf ( "\n\n�� %d�ð� %d�� �ɸ���.\n", hour, min );
	}
}