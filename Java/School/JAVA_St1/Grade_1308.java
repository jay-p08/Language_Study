//1308 ���翵
import java.util.*;
public class Four_op_1308sc {
	public static void main ( String [ ] arg ) {
		Scanner sc = new Scanner ( System.in );
		
		System.out.print ( " ù��° �Ǽ� : " );
		int number1 = sc.next(  );
		System.out.print ( " �ι�° �Ǽ� : " );
		int number2 = sc.next(  );
		
		System.out.printf ( number1 + "+" + number2 + "=" + ( number1 + number2) + \n );
		System.out.printf ( number1 + "-" + number2 + "=" + ( number1 - number2) + \n );
		System.out.printf ( number1 + "*" + number2 + "=" + ( number1 * number2) + \n );
		System.out.printf ( number1 + "/" + number2 + "=" + ( number1 / number2) + \n );
	}
}