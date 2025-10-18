import java.util.Scanner;

public class BanCountJumsu {
    public static void main(String[] args) {
        int[][] student;
        int sum, sumtotal = 0;
        double avg, avgtotal = 0;
        Scanner sc = new Scanner( System.in );

        System.out.print( "반이 총 몇개? >> " );
        int Class = sc.nextInt();
        System.out.print( "인원이 몇명? >> " );
        int Number = sc.nextInt();
        student = new int[Class][Number];

        for( int i = 0 ; i < student.length ; i++ ) {
            for( int j = 0 ; j < student[i].length ; j++ ) {
                System.out.print( ( i + 1 ) + "반의 " + ( j + 1 ) + "번 학생 점수 >> " );
                student[i][j] = sc.nextInt();
                sumtotal += student[i][j];
            }
        }
        System.out.println();

        System.out.println("반\t합계\t평균\t");
        System.out.println("--------------------");
        for( int i = 0 ; i < student.length ; i++ ) {
            sum = 0;
            for( int j = 0 ; j < student[i].length ; j++ ) {
                sum += student[i][j];
            }
            avg = sum / student[i].length;
            avgtotal += avg;
            System.out.printf( "%d반\t%d\t%.1f\n", i + 1, sum, avg );
        }

        avgtotal = avgtotal/student.length;

        System.out.printf( "전체 합계 %d, 전체평균 %.1f", sumtotal, avgtotal );

        sc.close();
    }
}
