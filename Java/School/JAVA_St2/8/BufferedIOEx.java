import java.io.*;
import java.util.Scanner;

public class BufferedIOEx {
    public static void main(String[] args) {
        FileReader fin = null;
        int c;
        try {
            fin = new FileReader("D:\\JAVA\\School_St1_2\\8\\Resorse\\test2.txt");
            BufferedOutputStream out = new BufferedOutputStream(System.out, 5);
            while ((c = fin.read()) != -1) {
                out.write(c);
            }
            // ���� �����Ͱ� ��� ��µ� ����
            new Scanner(System.in).nextLine();

            out.flush(); // ���ۿ� ���� �ִ� ���� ��� ���
            fin.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}