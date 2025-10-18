import java.util.Vector;

public class PointVectorEx {
    public static void main(String[] args) {
        Vector<Point> v = new Vector<Point>();

        v.add( new Point( 2, 3 ) );
        v.add( new Point( -5, 20 ) );
        v.add( new Point( 30, -8 ) );

        v.remove( 1 );

        // ���Ϳ� �ִ� Point ��ü ��� �˻��Ͽ� ���
        for( int i = 0 ; i < v.size() ; i++ ) {
            Point p = v.get( i ); // ���Ϳ��� i ��° Point ��ü ����
            System.out.println( p.toString() ); // p.toString()�� �̿��Ͽ� ��ü p ���
        }
    } // main
} // PointVectorEx

class Point {
    private int x, y;
    public Point( int x, int y ) {
        this.x = x;
        this.y = y;
    } // Point

    public String toString() {
        return "(" + x + ", " + y + " )";
    } // toString
}