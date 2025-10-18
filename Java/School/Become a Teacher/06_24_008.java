import java.util.*;
public class j06_22_007 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		int[] num = new int[6];
		int temp = 0;
		int cnt = 0;
		for ( int i = 0 ; i < num.length ; i++ ) {
			int random = (int)(Math.random() * 6 + 1 );
			num[i] = random;
			for ( int j = 0 ; j < i ; j++ ) 
				if ( num[i] == num[j] ) {
					i--;
					cnt++;
					break;
				}
			
		}
		for ( int i = 0 ; i < num.length-1 ; i++ )
			for ( int j = 0 ; j < num.length-1 ; j++ )
				if ( num[j] > num[j+1] ) {
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
				}
		System.out.printf ( "같은 번호가 나온 횟수 : %d\n로또 번호 : ", cnt );
		for ( int i = 0 ; i < num.length ; i++ )
			System.out.printf ( "%d ", num[i] );
	}
}