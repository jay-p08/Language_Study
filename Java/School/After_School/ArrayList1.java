import java.util.ArrayList;

public class ArrayList1 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();
        list.add( "이순신" );
        list.add( "강감찬" );
        list.add( "세종대왕" );

        list.forEach( System.out::println );
    }
}
