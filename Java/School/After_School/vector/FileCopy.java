package vector;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class FileCopy {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner( System.in );
        System.out.print( "원본파일명 >>> " );
        String originalFile = scan.next();

        System.out.print( "복사파일명 >>> ");
        String copyFile = scan.next();

        FileInputStream fis = new FileInputStream( "vector\\" + originalFile );
        FileOutputStream fos = new FileOutputStream( "vector\\" + copyFile );

        int a;
        while( ( a = fis.read() ) != -1 ) {
            fos.write( a );
        } // while
        fis.close();
        fos.close();
    }
}
