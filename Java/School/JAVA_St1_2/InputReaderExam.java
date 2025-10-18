import java.io.*;

public class InputReaderExam {
    public static void main( String[  ] args ) throws IOException {
        Reader reader = new InputStreamReader( System.in );
        while ( true ) {
            int i = reader.read();
            if( i == -1 ) break;
            char c = ( char ) i;
            System.out.print( c );
        }
        System.out.println();
    }
}
