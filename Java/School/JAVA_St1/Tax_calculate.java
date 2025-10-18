import java.util.*;
public class Tax_calculate {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "근로소득 (만 단위:): " );
		int salary = sc.nextInt();

		if ( salary <= 2000 ) System.out.printf ( "소득세 : %.0f만 원", salary*0.05 );
		else if ( salary <= 4000 ) System.out.printf ( "소득세 : %.0f만 원", salary*0.15 );
		else if ( salary <= 8000 ) System.out.printf ( "소득세 : %.0f만 원", salary*0.25 );
		else System.out.printf ( "소득세 : %.0f만 원", salary*0.40 );
	}
}