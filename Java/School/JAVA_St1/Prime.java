import java.util.*;
public class Prime {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "���� �Է� : " );
		int start = sca.nextInt();
		int cut = 0;
		for ( int i = 2 ; i <= start ; i++  ) {
			if ( start%i == 0 && start != i ) {
				System.out.printf ( "%d�� �Ҽ��� �ƴմϴ�.", start ); break;
			}
			else if ( start%i == 0 && start == i ) {
				System.out.printf ( "%d�� �Ҽ��Դϴ�.", start ); break;
			}
			if ( cut%10 == 0 ) System.out.println ();
			cut++;
		}
	}
}