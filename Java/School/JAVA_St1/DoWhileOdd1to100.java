import java.util.Scanner;
public class DoWhileOdd1to10 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner( System.in );
		int i = 1;
		do {
			if ( i%2 == 1 )
				System.out.printf ( "%d\n", i );
			i++;
		} while ( i <= 100 );
	}
}