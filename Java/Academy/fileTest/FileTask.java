package fileTest;

import java.io.*;

public class FileTask {
    public static void main(String[] args) throws IOException {
        BufferedWriter br = new BufferedWriter(new FileWriter(new File("animal.txt")));

        String[] str = new String[]{"사슴", "고라니", "너구리", "토끼"};

        for (int i = 0; i < str.length; i++) {
            br.write(str[i]);
            br.newLine();
        }

        BufferedReader br2 = new BufferedReader(new FileReader(new File("animal.txt")));

        for (int i = 0 ; i < str.length ; i++ ) {
            System.out.println(br2.readLine());
        }
        br.close();
    }
}