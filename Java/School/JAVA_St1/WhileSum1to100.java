import java.util.*;
public class WhileSum1to100 {
	public static void main ( String [ ] args ) {
		int i = 1, sum = 0;
		while ( i <= 100 ) {
			sum+=i;
			i++;
		}
		System.out.printf ( "%d", sum);
	}
}