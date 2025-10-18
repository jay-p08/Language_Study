import java.util.Arrays;
import java.util.Collections;

public class ArrayMathRandom {
    public static void main(String[] args) {
        Integer[] array = new Integer[10];

        for( int i = 0 ; i < array.length ; i++ ) {
            array[i] = (int)(Math.random() * 100 ) + 1;
        }

        System.out.println( Arrays.toString( array ) );

        Arrays.sort( array );
        
        System.out.println( "Max : " + array[ 9 ] );
        System.out.println( "Min : " + array[ 0 ] );

        Arrays.sort( array, Collections.reverseOrder() );

        System.out.println( Arrays.toString( array ) );
    }
}