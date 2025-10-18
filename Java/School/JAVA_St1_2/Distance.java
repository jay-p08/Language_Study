//import java.util.Scanner;
//
//public class Distance {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        System.out.println("첫번째 점 : ");
//        Point point1 = new Point(sc.nextInt(), sc.nextInt());
//
//        System.out.println("두번째 점 : ");
//        Point point2 = new Point(sc.nextInt(), sc.nextInt());
//
//        System.out.println(point1.distance(point2));
//    }
//}
//class Point {
//    private int x;
//    private int y;
//    public Point(int x, int y) {
//        this.x = x;
//        this.y = y;
//    }
//    int getX() {
//        return x;
//    }
//    int getY() {
//        return y;
//    }
//    double distance(Point p) {
//        return Math.sqrt(Math.pow(p.getX() - this.x, 2) + Math.pow(p.getY() - this.y, 2));
//    }
//}