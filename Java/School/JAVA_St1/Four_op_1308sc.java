//1308 ���翵
import java.util.*;
public class Four_op_1308sc {
	public static void main ( String [ ] arg ) {
		Scanner sc = new Scanner ( System.in );
		
		System.out.print ( " ù��° �Ǽ� : " );
		double number1 = sc.nextDouble(  );
		System.out.print ( " �ι�° �Ǽ� : " );
		double number2 = sc.nextDouble(  );
		
		System.out.printf ( number1 + " + " + number2 + " = " + ( number1 + number2) + "\n" );
		System.out.printf ( number1 + " - " + number2 + " = " + ( number1 - number2) + "\n" );
		System.out.printf ( number1 + " * " + number2 + " = " + ( number1 * number2) + "\n" );
		System.out.printf ( number1 + " / " + number2 + " = " + ( number1 / number2) + "\n" );
	}
}