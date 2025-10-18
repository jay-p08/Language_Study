import java.util.LinkedList;

public class LinkedMain {
    public static void main(String[] args) {
        LinkedList<String> earlBio = new LinkedList<>();
        String str1 = new String("Hello World!");
        String str2 = new String("My name is Earl");
        String str3 = new String("I love Java");
        String str4 = new String("I live in Canada");
        earlBio.add(str1); // 0번째 데이터 저장
        earlBio.add(str3); // 1번째 데이터 저장
        earlBio.add(1, str2); // 1번째에 str2값을 저장하고, 원래 1번째는 2번째로 밀려남
        System.out.println(earlBio);
        earlBio.remove(1); // 1번째 요소 삭제
        System.out.println(earlBio);
    }
}