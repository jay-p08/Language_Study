import java.util.*;
public class Fact_method {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "양수 입력 : " );
		int start = sca.nextInt();
		int n = Fact_Method ( start );
		System.out.print ( n );
	}
	static int Fact_Method ( int start ) {
		if ( start == 1 ) return 1;
		else return start*Fact_Method(start-1);
	}
}