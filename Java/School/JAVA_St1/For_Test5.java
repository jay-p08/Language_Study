import java.util.*;
public class For_Test3 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		int num = sc.nextInt();
		int cut = 0;
		int sum = 1, i = 0;
		for ( i = 1 ; i <= num ; i++  ) {
			cut++;
			sum += i*i;
			if ( i == 1 ) System.out.print ( "1 " );
			else System.out.printf ("+ ( %d*%d ) ", i, i);
			if ( cut%5 == 0 ) System.out.println();
		}
		System.out.printf (" = %d\t", sum-1 );
	}
}