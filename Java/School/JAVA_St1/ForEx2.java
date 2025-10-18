import java.util.Scanner;
public class ForEx2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int[] arr = new int[100];
		int sum = 0;
		for ( int i = 0 ; i < arr.length ; i++ ) {
			arr[i] = i+1;
			sum += arr[i];
		}
		System.out.printf ( "%d\n", sum);
	}
}