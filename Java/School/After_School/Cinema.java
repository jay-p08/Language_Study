import java.util.IllegalFormatConversionException;
import java.util.Scanner;

public class Cinema {
    public static void main(String[] args) throws IllegalFormatConversionException {
        Scanner sc = new Scanner(System.in);

        int Line = 10;
        int Seat = 10;
        int Temp = 1;

        int SelectLine;
        int SelectSeat;

        char SeatChar[][] = new char[Line][Seat];

        for (int i = 0; i < Line; i++) {
            for (int j = 0; j < Seat; j++) {
                SeatChar[i][j] = 'O';
            }
        }

        do {
            System.out.println( "     ======= SCREEN =======" );
            for( int i = 0 ; i < 10 ; i++ ) {
                System.out.printf( "%3d", i+1 );
            }
            System.out.println();
            for ( int i = 0; i < Line ; i++ ) {
                System.out.print(i+1);
                for ( int j = 0 ; j < Seat ; j++ ) {
                    if ( SeatChar[i][j] == 'X') {
                        System.out.print( " \u001B[31m" + SeatChar[i][j] + "\u001B[0m " );
                    } else {
                        System.out.printf( "%2c ", SeatChar[i][j] );
                    }
                    
                }
                System.out.println();
            }

            System.out.print("\n예약할 행 입력 : ");
            SelectLine = sc.nextInt();
            System.out.print( "\n예약할 열 입력 : " );
            SelectSeat = sc.nextInt();

            if( SelectLine == 0 ) {
                System.out.println( "\n프로그램을 종료합니다.\n" );
                break;
            }
        
            for (int i = 0; i < Line; i++) {
                for (int j = 0; j < Seat; j++) {
                    if ( SelectLine-1 == i && SelectSeat-1 == j ) {
                        if( SeatChar[i][j] == 'X' ) System.out.print( "\n이미 예약된 자석입니다 다른 자석을 골라주세요\n" );
                        else SeatChar[i][j] = 'X';
                        break;
                    }
                }
            }

        } while (true);
    }
}