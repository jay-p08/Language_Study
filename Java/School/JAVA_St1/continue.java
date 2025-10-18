import java.util.Scanner;
public class cuntinue {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		System.out.print ( "배열 길이 입력 : " );
		int num2 = sc.nextInt();
		int num[] = new int [num2];
		for ( int i = 0 ; i < num.length ; i++ ) 	{
			System.out.print ( "정수 입력 : " );
			int num1 = sc.nextInt();
			num[i] = num1;
		}
		for ( int i = 0 ; i < num.length ; i++ )
			System.out.printf ( "%d\t", num[i] );
	}
}