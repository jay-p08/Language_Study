/*
import java.util.Scanner;

public class ShapeExamMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        One o1 = new One(sc.nextInt());

        System.out.printf("원의 둘레 : %.2f\n", o1.getCircumference());
        System.out.printf("원의 면적 : %.2f\n", o1.getArea());
    }
}
abstract class ShapeExam {
    public abstract double getArea();
    public abstract double getCircumference();
}
class One extends ShapeExam {
    private int radius;
    public One(int radius) {
        this.radius = radius;
    }

    public double getArea() {
        return Math.PI * Math.pow(radius, 2);
    }
    public double getCircumference() {
        return 2 * Math.PI * radius;
    }
}*/
