package fileTest;

import java.io.*;

public class FileTest {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("test.txt")));

        bw.write("안녕하세요");
        bw.newLine();
        bw.write("고생하셨습니다.");

        bw.close();

        BufferedReader br = new BufferedReader(new FileReader(new File("test.txt")));

        System.out.println(br.readLine());
    }
}
