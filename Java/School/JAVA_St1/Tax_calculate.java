import java.util.*;
public class Tax_calculate {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "�ٷμҵ� (�� ����:): " );
		int salary = sc.nextInt();

		if ( salary <= 2000 ) System.out.printf ( "�ҵ漼 : %.0f�� ��", salary*0.05 );
		else if ( salary <= 4000 ) System.out.printf ( "�ҵ漼 : %.0f�� ��", salary*0.15 );
		else if ( salary <= 8000 ) System.out.printf ( "�ҵ漼 : %.0f�� ��", salary*0.25 );
		else System.out.printf ( "�ҵ漼 : %.0f�� ��", salary*0.40 );
	}
}