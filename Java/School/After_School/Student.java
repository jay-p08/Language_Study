import java.util.Scanner;
import java.math.*;

public class Student {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        int[][] student = new int[3][2];
        double sum = 0;
        
        for( int i = 0 ; i < student.length ; i++ ) {
            for( int j = 0 ; j < student[i].length ; j++ ) {
                student[i][j] = sc.nextInt();
                sum += student[i][j];
            }
        }
        sum = sum/6;

        System.out.printf("%.1f", sum);
    }
}
