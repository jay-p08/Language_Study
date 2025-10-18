import java.util.Scanner;
public class DoWhileMax {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int num, max = 0, min = 0;
		do {
			System.out.print ( "정수를 입력해주세요. : " );
			num = sc.nextInt();
			if ( num > max ) max = num;
			if ( num < max ) min = num;
		} while ( num != 0 );
		System.out.printf ( "입력된 정수중 가장 작은 수는 %d입니다.\n", min );
		System.out.printf ( "입력된 정수중 가장 큰 수는 %d입니다.\n", max );
	}
}