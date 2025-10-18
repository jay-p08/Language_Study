import java.util.*;
public class java004 {
	public static void main ( String [] args ) {
		Scanner sc = new Scanner ( System.in );
		String[] str = new String[]{"양념", "후라이드", "간장"};
		int cnt = 0;
		System.out.print ( "치킨 종류 : " );
		String st = sc.next();
		for ( int i = 0 ; i < str.length ; i++ ) {
			switch ( str[i] ) {
				case "간장" : ;
				case "후라이드" : ;
				case "양념" : System.out.printf ( "%s치킨 배달 가능.", st ); break;
				default : System.out.printf ( "%s치킨 배달 불가.", st ); break;
			} break;
		}
	}
}