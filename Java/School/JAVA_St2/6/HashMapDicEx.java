import java.util.*;
public class HashMapDicEx {
    public static void main(String[] args) {
        HashMap<String, String> dic = new HashMap<String, String>();

        dic.put("baby", "�Ʊ�"); // "baby"�� key, "�Ʊ�"�� value
        dic.put("love", "���");
        dic.put("apple", "���");
        // ���� �ܾ �Է¹ް� �ѱ� �ܾ� �˻�. "exit" �Է¹����� ����
        Scanner scan = new Scanner(System.in);
        while(true) {
            System.out.print("ã�� ���� �ܾ��?");
            String eng = scan.next();
            if(eng.equals("exit")) {
                System.out.println("�����մϴ�...");
                break;
            }
        // �ؽøʿ��� 'Ű' eng�� '��' kor �˻�
        String kor = dic.get(eng);
        if(kor == null)
            System.out.println(eng + "�� ���� �ܾ� �Դϴ�.");
        else
            System.out.println(kor);
        }
    }
}