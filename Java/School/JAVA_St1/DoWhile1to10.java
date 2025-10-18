import java.util.Scanner;
public class DoWhile1to10 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner( System.in );
		int i = 1;
		do {
			System.out.printf ( "%d\n", i );
			i++;
		} while ( i <= 10 );
	}
}