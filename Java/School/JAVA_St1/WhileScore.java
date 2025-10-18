import java.util.*;
public class WhileScore {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner ( System.in );
		double i = 1.0, num = 0, sum = 0;
		while ( true) {
			System.out.print ( "Á¡¼ö : " );
			int score = sc.nextInt();
			sum+=score;
			if ( score == 0 ) break;
			i++;
		}
		num = sum/(i-1);
		System.out.printf ( "ÇÕ : %.0f, Æò±Õ : %f", sum, num);
	}
}