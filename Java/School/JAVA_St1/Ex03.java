import java.util.*;
public class Ex03 {
	public static void main(String[] args) {
		Scanner sca = new Scanner ( System.in );
		System.out.print ( "���� �� �Է� : " );
		int num1 = sca.nextInt();
		System.out.print ( "������ �� �Է� : " );
		int num2 = sca.nextInt();
		for(int i=1 ; i<6 ; i++) {
			for(int j=0 ; j<6-i ; j++) {
				System.out.printf ( "%d * %d = %d", i, j, i*j );
			}
			for(int j=0 ; j<i ; j++) {
				System.out.print("*");
			}		
		System.out.println();
		}

	}

}