import java.util.*;
public class getMax {
	public static void main ( String [ ] args )  {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "ù ��° �� �Է� : " );
		int num = sca.nextInt();
		System.out.print ( "�� ��° �� �Է� : " );
		int num1 = sca.nextInt();
		System.out.print ( "�� ��° �� �Է� : " );
		int num2 = sca.nextInt();
		
		if ( num < num1 && num < num2 )
			System.out.printf ( "%d�� %d�� %d �� ���� ���� ���� %d�Դϴ�.", num, num1, num2, num );
		else if ( num1 < num && num1 < num2 )
			System.out.printf ( "%d�� %d�� %d �� ���� ���� ���� %d�Դϴ�.", num, num1, num2, num1);
		else 
			System. out.printf ( "%d�� %d�� %d �� ���� ���� ���� %d�Դϴ�.", num, num1, num2, num2);
	}
}