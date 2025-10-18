import java.util.*;
public class For_Test1 {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		int cut = 1;
		char op;
		for ( int i = 1 ; i <= 100 ; i++  ) {
			if ( i%10%3 == 0 && i%10 != 0 ) {
				op = 'X';
				System.out.printf ("%c\t", op);
			}
			else System.out.printf ("%d\t", i);
			if ( i%10 == 0 )
				System.out.println();
			cut++;
		}
	}
}