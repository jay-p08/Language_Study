package vector;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Fileout {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = new FileOutputStream( "vector\\fos.txt" );
        fos.write( 'L' );
        fos.write( 'O' );
        fos.write( 'V' );
        fos.write( 'E' );
        fos.close();

        System.out.println( "저장 완료" );

        FileInputStream fis = new FileInputStream( "vector\\fos.txt" );

        int a;

        while ( ( a = fis.read() ) != -1 ) {
            System.out.print( (char)a );
        } // while
        fis.close();
    }
}