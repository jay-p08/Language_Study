import java.util.*;

public class HashMapScoreEx {
    public static void main(String[] args) {
        // ����� �̸��� ������ ����ϴ� HashMap �÷��� ����
        HashMap<String, Integer> javaScore = new HashMap<String, Integer>();
        // 5 ���� ���� ����
        javaScore.put("������", 97);
        javaScore.put("�Ͽ���", 88);
        javaScore.put("���Ƹ�", 98);
        javaScore.put("�̵���", 70);
        javaScore.put("��¿�", 99);
        System.out.println("HashMap�� ��� ����:" + javaScore.size());
        // ��� ����� ���� ���.
        // javaScore�� ��� �ִ� ��� (key, value) �� ���
        // key ���ڿ��� ���� ���� Set �÷��� ����
        Set<String> keys = javaScore.keySet();
        // key ���ڿ��� ������� ������ �� �ִ� Iterator ����
        Iterator<String> it = keys.iterator();
        while (it.hasNext()) {
            String name = it.next();
            int score = javaScore.get(name);
            System.out.println(name + " : " + score);
        }
    }
}