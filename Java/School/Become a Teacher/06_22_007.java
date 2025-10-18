import java.util.*;
public class j06_22_007 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "출력할 수 입력 : " );
		int a = sc.nextInt();
		int[] num = new int[a];
		int odd1 = 0;
		int even1 = 0;
		for ( int i = 0 ; i < num.length ; i++ ) {
			int random = (int)(Math.random() * 9 + 1 );
			num[i] = random;
		}
		for ( int i = 0 ; i < num.length ; i++ ) {
			if ( num[i]%2 == 0 ) even1++;
			else odd1++;
		}
		int[] odd = new int[odd1];
		int[] even = new int[even1];
		int even_cnt = 0, odd_cnt = 0;
		for ( int i = 0 ; i < num.length ; i++ ) {
			if ( num[i]%2 == 0 ) {
				even[even_cnt] = num[i];
				++even_cnt;
			}
			else {
				odd[odd_cnt] = num[i];
				++odd_cnt;
			}
		}
		System.out.print ( "짝수 : " );
		for ( int i = 0 ; i < even_cnt ; i++ )
			System.out.printf ( "%d ", even[i] );
		System.out.print ( "\n홀수 : " );
		for ( int i = 0 ; i < odd_cnt ; i++ )
			System.out.printf ( "%d ", odd[i] );
	}
}