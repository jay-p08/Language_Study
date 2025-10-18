import java.util.Scanner;
public class DoWhileSum1to100 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner( System.in );
		int i = 1, sum = 0;
		do {
			sum+=i;
			i++;
		} while ( i <= 100 );
		System.out.printf ( "%d\n", sum );
	}
}