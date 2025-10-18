public class DoWhile {
    public static void main(String[] args) {
        char ch = 'a';
        do {
            System.out.printf( "%2c ", ch );
            ch += 1;
            if ( ch > 'z' ) break;
        } while( true );
    }
}
