import java.util.Scanner;
public class DoWhileMax {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int num, max = 0, min = 0;
		do {
			System.out.print ( "������ �Է����ּ���. : " );
			num = sc.nextInt();
			if ( num > max ) max = num;
			if ( num < max ) min = num;
		} while ( num != 0 );
		System.out.printf ( "�Էµ� ������ ���� ���� ���� %d�Դϴ�.\n", min );
		System.out.printf ( "�Էµ� ������ ���� ū ���� %d�Դϴ�.\n", max );
	}
}