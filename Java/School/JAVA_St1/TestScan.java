import java.util.*;
public class TestScan {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.printf ( " �̸��� �Է��� �ּ���. : " );
		String name = sca.nextLine();
		
		System.out.printf ( " ����� ���̸� �Է��� �ּ��� : " );
		byte age = Byte.parseByte(sca.nextLine());
		
		System.out.printf ( " ����� Ű�� �Է��� �ּ��� : " );
		double high = Double.parseDouble(sca.nextLine());
		
		System.out.printf ( " ����... �̸���!! %s�Դϴ�. �׸��� ���̴� %d�� �̳׿�.\nŰ�� %.1f�̳׿�.\n", name, age, high );

		System.out.printf ( " ����� �̸��� �Է��� �ּ���. : " );
		name = sca.nextLine();
		
		System.out.printf ( " ����� ���̸� �Է��� �ּ��� : " );
		age = sca.nextByte();
		
		System.out.printf ( " ����� Ű�� �Է��� �ּ��� : " );
		high = sca.nextDouble();
		
		System.out.printf ( " ����... �̸���!! %s�Դϴ�. �׸��� ���̴� %d�� �̳׿�.\nŰ�� %.1f�̳׿�.", name, age, high );
	}
}