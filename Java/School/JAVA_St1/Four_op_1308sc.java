//1308 박재영
import java.util.*;
public class Four_op_1308sc {
	public static void main ( String [ ] arg ) {
		Scanner sc = new Scanner ( System.in );
		
		System.out.print ( " 첫번째 실수 : " );
		double number1 = sc.nextDouble(  );
		System.out.print ( " 두번째 실수 : " );
		double number2 = sc.nextDouble(  );
		
		System.out.printf ( number1 + " + " + number2 + " = " + ( number1 + number2) + "\n" );
		System.out.printf ( number1 + " - " + number2 + " = " + ( number1 - number2) + "\n" );
		System.out.printf ( number1 + " * " + number2 + " = " + ( number1 * number2) + "\n" );
		System.out.printf ( number1 + " / " + number2 + " = " + ( number1 / number2) + "\n" );
	}
}