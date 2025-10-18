import java.util.*;
public class TestScan {
	public static void main ( String [ ] args ) {
		Scanner sca = new Scanner ( System.in );
		System.out.printf ( " 이름을 입력해 주세요. : " );
		String name = sca.nextLine();
		
		System.out.printf ( " 당신의 나이를 입력해 주세요 : " );
		byte age = Byte.parseByte(sca.nextLine());
		
		System.out.printf ( " 당신의 키를 입력해 주세요 : " );
		double high = Double.parseDouble(sca.nextLine());
		
		System.out.printf ( " 너의... 이름은!! %s입니다. 그리고 나이는 %d살 이네요.\n키는 %.1f이네요.\n", name, age, high );

		System.out.printf ( " 당신의 이름을 입력해 주세요. : " );
		name = sca.nextLine();
		
		System.out.printf ( " 당신의 나이를 입력해 주세요 : " );
		age = sca.nextByte();
		
		System.out.printf ( " 당신의 키를 입력해 주세요 : " );
		high = sca.nextDouble();
		
		System.out.printf ( " 너의... 이름은!! %s입니다. 그리고 나이는 %d살 이네요.\n키는 %.1f이네요.", name, age, high );
	}
}