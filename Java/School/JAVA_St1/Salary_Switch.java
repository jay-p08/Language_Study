import java.util.*;
public class Salary_Switch {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "현 연봉을 입력하세요 : " );
		double currentSalary = sc.nextDouble();
		System.out.print ( "근무평가등급을 입력하세요 : " );
		String rating = sc.next();
		double raise = 0.0;

		raise = setRating ( rating, currentSalary );
		double newSalary = raise+currentSalary;
		System.out.printf ( "연봉인상액 : %.0f\n새 연봉인상액 : %.0f\n", raise, newSalary );
	}
	static double setRating ( String rating, double currentSalary ) {
		double raise = 0.0;
		switch ( rating ) {
			case "우수" : raise = 0.06; break;
			case "보통" : raise = 0.04; break;
			case "불량" : raise = 0.02; break;
		}
		raise = currentSalary*raise;
		return raise;
	}
}