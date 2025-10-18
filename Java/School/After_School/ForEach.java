import java.util.Arrays;

public class ForEach {
    public static void main(String[] args) {
        String[] fruits = { "orange", "apple", "mango" };
        for( String i : fruits ) {
            System.out.print( " " + i );
        }
        System.out.println();

        System.out.println( Arrays.toString( fruits ));
    }
}
