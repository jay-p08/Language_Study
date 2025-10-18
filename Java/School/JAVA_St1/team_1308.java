import java.util.*;
public class team_1308 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print ( "辟肺家垫 (父 窜困:): " );
		int money = sc.nextInt();

		if ( money <= 2000 ) System.out.printf ( "家垫技 : %.0f父", money*0.05 );
		else if ( money <= 4000 ) System.out.printf ( "家垫技 : %.0f父", money*0.15 );
		else if ( money <= 8000 ) System.out.printf ( "家垫技 : %.0f父", money*0.25 );
		else System.out.printf ( "家垫技 : %.0f父", money*0.40 );
	}
}