public class Enum {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        System.out.println( "arr : " + arr );
        System.out.println( "arr[0] : " + arr[0] );

        double[] Darr = { 1.2, 3.4  };
        System.out.println( "Darr : " + Darr );
        System.out.println( "Darr[0] : " + Darr[0] );

        enum week{ mon, tus, wends, thu, fri, sat, sum };
        System.out.println( "week : " + week.values() );

        for( week day : week.values() ) {
            System.out.print( day + "day " );
        }
    }
}
