import java.util.LinkedList;

public class LinkedMain {
    public static void main(String[] args) {
        LinkedList<String> earlBio = new LinkedList<>();
        String str1 = new String("Hello World!");
        String str2 = new String("My name is Earl");
        String str3 = new String("I love Java");
        String str4 = new String("I live in Canada");
        earlBio.add(str1); // 0��° ������ ����
        earlBio.add(str3); // 1��° ������ ����
        earlBio.add(1, str2); // 1��°�� str2���� �����ϰ�, ���� 1��°�� 2��°�� �з���
        System.out.println(earlBio);
        earlBio.remove(1); // 1��° ��� ����
        System.out.println(earlBio);
    }
}