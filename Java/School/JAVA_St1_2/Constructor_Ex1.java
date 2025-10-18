//
//import java.util.Scanner;
//
//public class Constructor_Ex1 {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        IntSum Is = new IntSum(sc.nextInt(), sc.nextInt());
//        IntSum Is1 = new IntSum(sc.nextInt(), sc.nextInt(), sc.nextInt());
//        IntSum Is2 = new IntSum(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
//        Is.Print1();
//        System.out.println(Is.sum);
//        Is1.Print2();
//        System.out.println(Is1.sum);
//        Is2.Print3();
//        System.out.println(Is2.sum);
//
//    }
//}
//class IntSum {
//    private int A;
//    private int B;
//    private int C;
//    private int D;
//    int sum;
//    public IntSum(int A, int B) {
//        this.A = A; this.B = B;
//        this.sum = A+B;
//    }
//    public IntSum(int A, int B, int C) {
//        this(A, B);
//        this.C = C;
//
//        sum += C;
//    }
//    public IntSum(int A, int B, int C, int D) {
//        this(A, B, C);
//        this.D = D;
//
//        sum += D;
//    }
//    public void Print1() {
//        System.out.printf("\n%d + %d = ", A, B);
//    }
//    public void Print2() {
//        System.out.printf("\n%d + %d + %d = ", A, B, C);
//    }
//    public void Print3() {
//        System.out.printf("\n%d + %d + %d + %d = ", A, B, C, D);
//    }
//}