import java.util.Scanner;

public class Break {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] str = new String[10];
        int i = 0;
        while (true) {
            str[i] = sc.nextLine();
            if ( str[i].equals("exit")) {
                break;
            }
            i++;
        }

        for( int j = 0 ; j < i ; j++ ) {
            System.out.println(str[j]);
        }
    }
}
