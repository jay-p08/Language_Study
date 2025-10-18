import java.util.*;
import static java.lang.System.out;
public class date {
	public static void main ( String [] args ) {
		String[] date = new String[]{"피시방", "당구장", "스크린야구장", "헬스장", "전쟁박물관"};
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
		out.printf ( "\n철수가 만든 지리는 데이트 코스\n영희와의 데이트 코스는 : %s ", date[0] );
		for ( int i = 1 ; i < date.length ; i++ )
			out.printf ( "-> %s ", date[i] );
		for ( int i = 0 ; i < date.length ; i++ )
			min += bun[i];
		for ( int i = 0 ; i < date.length ; i++ ) 
			if ( min > 60 ) {
				min -= 60;
				hour += 1;
			}
		out.printf ( "\n\n총 %d시간 %d분 걸린다.\n", hour, min );
	}
}