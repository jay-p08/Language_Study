import java.util.*;
public class Max {
	public static void main ( String [ ] args )  {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "ù ��° �� �Է� : " );
		int num = sca.nextInt();
		System.out.print ( "�� ��° �� �Է� : " );
		int num1 = sca.nextInt();
		
		if ( num > num1 ) {
			System.out.printf ( "%d�� %d �� ū ���� %d�Դϴ�.", num, num1, num );
		} else {
			System.out.printf ( "%d�� %d �� ū ���� %d�Դϴ�.", num, num1, num1 );
		}
	}
}