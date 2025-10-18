import java.io.*;

public class FileExam {
    public static void main( String[  ] args ) {
        char[  ] buffer = new char[ 100 ];
        try {
            FileReader fr = new FileReader("File/datar.txt" );
            FileWriter fw = new FileWriter("File/dataw.txt" );
            fr.read( buffer, 6, 100-6 );
            String str = new String( buffer );
            System.out.println( str );
            fw.write( buffer );
            fw.flush();
        } catch ( Exception e ) {
            System.out.println( e.toString() );
        }
    }
}
