import java.io.*;

public class FileReaderEx {
    public static void main(String[] args) {
        FileReader fin = null;
        try {
            fin = new FileReader("D:\\JAVA\\School_St1_2\\8\\Resorse");
            int c;
            while ((c = fin.read()) != -1) { // �� ���ھ� ���� ������ �б�
                System.out.print((char) c);
            }
            fin.close();
        } catch (IOException e) {
            System.out.println("����� ����");
        }
    }
}