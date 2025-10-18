import java.util.*;
public class Scanner_1308 {
	public static void main ( String [ ] args ) {
		Scanner sc = new Scanner( System.in );
		int time = Integer.parseInt(args[0]);

		System.out.printf( "%d분은 %d일 %d시 %d분 입니다. ", time, (time/1440), (time/60)%24, time%60);
	}
}