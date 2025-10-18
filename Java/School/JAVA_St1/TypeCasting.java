import java.util.*;
public class TypeCasting {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner(System.in);
		System.out.print("사각형의 밑면 : ");
		int number = sc.nextInt();

		System.out.print("사각형의 높이 : ");
		int high = sc.nextInt();

		System.out.println( "사각형의 넓이 : " + number*high );
	}
}