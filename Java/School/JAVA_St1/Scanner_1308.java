import java.util.*;
public class Scanner_1308 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner( System.in );
		int time = Integer.parseInt(args[0]);

		System.out.printf( "%d���� %d�� %d�� %d�� �Դϴ�. ", time, (time/1440), (time/60)%24, time%60);
	}
}