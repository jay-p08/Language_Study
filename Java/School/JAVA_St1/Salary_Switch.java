import java.util.*;
public class Salary_Switch {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "�� ������ �Է��ϼ��� : " );
		double currentSalary = sc.nextDouble();
		System.out.print ( "�ٹ��򰡵���� �Է��ϼ��� : " );
		String rating = sc.next();
		double raise = 0.0;

		raise = setRating ( rating, currentSalary );
		double newSalary = raise+currentSalary;
		System.out.printf ( "�����λ�� : %.0f\n�� �����λ�� : %.0f\n", raise, newSalary );
	}
	static double setRating ( String rating, double currentSalary ) {
		double raise = 0.0;
		switch ( rating ) {
			case "���" : raise = 0.06; break;
			case "����" : raise = 0.04; break;
			case "�ҷ�" : raise = 0.02; break;
		}
		raise = currentSalary*raise;
		return raise;
	}
}