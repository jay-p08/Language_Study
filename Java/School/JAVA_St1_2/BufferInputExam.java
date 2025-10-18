import java.io.*;

public class BufferInputExam {
    public static void main( String[  ] args ) {
        BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
        String s = "  ";
        try {
            s = in.readLine();
        } catch ( Exception e ) {
            System.out.println( "Error : " + e.toString() );
        }
        System.out.println( s );
    }
}
