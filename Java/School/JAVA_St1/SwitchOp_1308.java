
import java.util.*;
public class SwitchOp_1308 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		System.out.print ( "�� �Է� : " );
		int number = sc.nextInt();
		if ( number%3 == 0 ) {
			System.out.printf ( "%d�� 3�� ����̴�.\n", number );
		} else if ( number%5 == 0 ) {
			System.out.printf ( "%d�� 5�� ����̴�.\n", number );
		} else if ( number%8 == 0 ) {
			System.out.printf ( "%d�� 8�� ����̴�.\n", number );
		} else {
			System.out.print ( "��� ����� �ƴϴ�." );
		}
	}
}