import java.util.Scanner;
import java.util.Vector;

public class suhang2305_04 {
    public static void printBig( Vector v ) {
        if( v.size() == 0 ) {
            System.out.println( "���� �ϳ��� ����" );
            return;
        }
        int max = 0;
        for( int i = 0 ; i < v.size() ; i++ ) {
            if( (int)v.elementAt(i)> max ) max = (int)v.elementAt(i);
        }
        System.out.println( "���� ū ���� " + max );
    }

    public static void main(String[] args) {
        Vector<Integer> v = new Vector<Integer>();
        Scanner scan = new Scanner( System.in );
        System.out.print( "����(-1�� �Էµ� ������) >> " );
        do {
            int temp = 0;
            temp = scan.nextInt();
            if ( temp == -1 ) {
                break;
            } else {
                v.add( temp );
            }            
        } while ( true );
        printBig( v );

        scan.close();
    }
}