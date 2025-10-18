import java.io.*;

public class BufferedReaderExam {
    public static void main( String[  ] args ) {
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
        try {
            String aa = br.readLine();
            System.out.println( aa );
        } catch ( IOException e ) {
            System.out.println( "정상 처리" + e.getMessage() );
        }
    }
}
