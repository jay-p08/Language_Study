package vector;

import java.util.Vector;

public class vector {
    public static void main(String[] args) {
        Vector<String> v = new Vector<String>();
        String s;

        for( int i = 0 ; i < args.length ; i++ ) {
            v.addElement( args[i] );
            s = v.elementAt(i);
        } // for
        for( int i = 0 ; i < v.size() ; i++ ) {
            s = ( String )v.elementAt( i );
            System.out.printf( "vector >>> %s\n", s );
        } // for
    } // main()
} // Vector
