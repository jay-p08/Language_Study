import java.io.*;

public class FileOutputStreamEx {
    public static void main(String[] args) {
        byte b[] = { 7, 51, 3, 4, -1, 24 };
        try {
            FileOutputStream fout = new FileOutputStream("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out");
            for (int i = 0; i < b.length; i++)
                fout.write(b[i]); // �迭 b�� ���̳ʸ��� �״�� ���
            fout.close();
        } catch (IOException e) {
            System.out.println("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out�� ������ �� �������ϴ�. ��θ��� Ȯ���� �ּ���");

            return;
        }
        System.out.println("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out�� �����Ͽ����ϴ�.");
    }
}