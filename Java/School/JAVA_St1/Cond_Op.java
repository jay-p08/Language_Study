import java.util.*;
public class Cond_Op {
	public static void main ( String [ ] arg ) {
		Scanner sc = new Scanner ( System.in );
		
		System.out.printf ( "���� �Է� : " );
		int num = sc.nextInt();
		int sum = num%2;

		
		char string = ( num%2 == 0 ) ? '¦' : 'Ȧ' ;
		System.out.printf ( "%d��(��) %s���Դϴ�.", num, string );
	}
}