import java.io.*;

public class FileStreamExam {
    public static void main( String[  ] args ) {
        byte[] b = new byte[ 1024 ];
        try {
            FileInputStream fis = new FileInputStream("File/tin.txt" );
            FileOutputStream fos = new FileOutputStream("File/tout.txt" );

            fis.read( b );
            fos.write( b );

            fis.close();
            fos.close();
        } catch ( IOException e ) {
            System.out.println( e.getMessage() );

        } catch ( Exception e ) {
            System.out.println( "알 수 없는 오류" + e.getMessage() );
        }
        finally {
            System.out.println( "프로그램 정상 실행." );
        }
    }
}
