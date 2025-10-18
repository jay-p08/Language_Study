// SuperEx 클래스: 실행을 담당하는 메인 클래스
public class SuperEx {
    public static void main(String[] args) {
        // ColorPoint1 객체를 생성하면서 (x=5, y=6, color="Blue") 값을 전달
        ColorPoint1 cp = new ColorPoint1(5, 6, "Blue");

        // 생성한 객체의 색상과 좌표를 출력하는 메서드 호출
        cp.showColorPoint();
    }
}

// 좌표를 저장하는 Point1 클래스 (부모 클래스)
class Point1 {
    private int x, y; // x, y 좌표값을 저장하는 변수

    // 기본 생성자: x와 y를 0으로 초기화
    public Point1() {
        this.x = this.y = 0;
    }

    // 매개변수가 있는 생성자: 전달받은 값으로 x, y 초기화
    public Point1(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // 좌표 값을 출력하는 메서드
    public void showPoint() {
        System.out.println(this.x + ", " + this.y);
    }
}

// 색상을 포함한 좌표 클래스 (Point1을 상속받음)
class ColorPoint1 extends Point1 {
    private String color; // 색상을 저장하는 변수

    // 생성자: x, y 좌표와 색상을 받아 초기화
    public ColorPoint1(int x, int y, String color) {
        super(x, y); // 부모 클래스(Point1)의 생성자를 호출하여 x, y 값을 설정
        this.color = color; // 색상 값 설정
    }

    // 색상과 좌표를 출력하는 메서드
    public void showColorPoint() {
        System.out.println(this.color); // 색상 출력
        showPoint(); // 부모 클래스의 showPoint() 메서드를 호출하여 좌표 출력
    }
}
