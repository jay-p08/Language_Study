import java.util.*;
public class team_1308 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "�ٷμҵ� (�� ����:): " );
		int money = sc.nextInt();

		if ( money <= 2000 ) System.out.printf ( "�ҵ漼 : %.0f��", money*0.05 );
		else if ( money <= 4000 ) System.out.printf ( "�ҵ漼 : %.0f��", money*0.15 );
		else if ( money <= 8000 ) System.out.printf ( "�ҵ漼 : %.0f��", money*0.25 );
		else System.out.printf ( "�ҵ漼 : %.0f��", money*0.40 );
	}
}