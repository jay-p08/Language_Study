import java.util.*;
public class For_Test3 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		int num = sc.nextInt();
		int cut = 0;
		double sum = 0.0, i = 0.0;
		for ( i = 1.0 ; i <= num ; i++  ) {
			cut++;
			sum += 1.0/i;
			if ( i == 1 ) System.out.print ( "1 " );
			else System.out.printf ("+ 1/%.0f ", i);
			if ( cut%5 == 0 ) System.out.println();
		}
		System.out.printf (" = " + sum + "\t" );
	}
}