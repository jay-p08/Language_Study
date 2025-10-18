public class For1to10sum {
	public static void main ( String [ ] args ) {
		int sum = 0;
		for ( int i = 1 ; i <= 10 ; i++ ) {
			sum += i;
		}
		System.out.printf ( "%d ", sum );
	}
}