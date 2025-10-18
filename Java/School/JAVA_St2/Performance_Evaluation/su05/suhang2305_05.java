import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class suhang2305_05 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print( "학번을 입력하세요 : ");
        String id = sc.next();

        try (BufferedReader reader = new BufferedReader(new FileReader("su05\\student2305.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] userInfo = line.split(" ");
                if (userInfo[0].equals(id)) {
                    System.out.println( line );
                    return;
                }
            }
        } catch (IOException e) {

        }
        System.out.println( "해당하는 학번이 존재하지 않습니다." );
        return;
                
    }
}
