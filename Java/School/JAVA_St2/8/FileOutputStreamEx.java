import java.io.*;

public class FileOutputStreamEx {
    public static void main(String[] args) {
        byte b[] = { 7, 51, 3, 4, -1, 24 };
        try {
            FileOutputStream fout = new FileOutputStream("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out");
            for (int i = 0; i < b.length; i++)
                fout.write(b[i]); // 배열 b의 바이너리를 그대로 기록
            fout.close();
        } catch (IOException e) {
            System.out.println("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out에 저장할 수 없었습니다. 경로명을 확인해 주세요");

            return;
        }
        System.out.println("D:\\JAVA\\School_St1_2\\8\\Resorse\\test.out을 저장하였습니다.");
    }
}