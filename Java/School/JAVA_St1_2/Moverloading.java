/*import java.util.Scanner;

public class Moverloading {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("* 1.정사각형\t*\n* 2.직사각형\t*\n* 3.육면체\t*");
        System.out.print("입력 선택 : ");
        int menu = sc.nextInt();
        switch (menu) {
            case 1 : System.out.print("정사각형의 변의 길이 입력 : ");
                     Loading square = new Loading(sc.nextInt());
                     System.out.printf("정사각형의 넓이 : %d", square.cals(square.getWidth())); break;

            case 2 : System.out.print("직사각형의 가로 세로 입력 : ");
                     Loading oblong = new Loading(sc.nextInt(), sc.nextInt());
                     System.out.printf("직사각형의 넓이 : %d", oblong.cals(oblong.getWidth(), oblong.getHeight())); break;

            case 3 : System.out.println("육면체의 부피 입력 : ");
                     Loading hexahedron = new Loading(sc.nextInt(), sc.nextInt(), sc.nextInt());
                     System.out.printf("육면체의 부피 : %d", hexahedron.cals(hexahedron.getWidth(), hexahedron.getHeight(), hexahedron.getLength())); break;

            default : System.out.println("잘못된 값을 입력하셨습니다.");
        }
    }

}
class Loading {
    private int width;
    private int height;
    private int length;

    public Loading(int width) {
        this.width = width;
    }
    public Loading(int width, int length) {
        this.width = width;
        this.length = length;
    }
    public Loading(int width, int length, int height) {
        this(width, length);
        this.height = height;
    }

    int cals(int a, int b, int c) {
        return a*b*c;
    }
    int cals(int a, int b) {
        return a*b;
    }
    int cals(int a) {
        return a*a;
    }

    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    int getLength() {
        return length;
    }
}*/