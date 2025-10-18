// ColorPointEx 클래스: 프로그램 실행을 담당하는 메인 클래스
public class ColorPointEx {
    public static void main(String[] args) {
        // Point 객체 생성
        Point p = new Point();
        p.set(1, 2); // 좌표값 (1,2) 설정
        p.showPoint(); // 설정한 좌표값 출력

        // ColorPoint 객체 생성
        ColorPoint cp = new ColorPoint();
        cp.set(3, 4); // 좌표값 (3,4) 설정 (부모 클래스 메서드 사용)
        cp.setColor("red"); // 색상을 "red"로 설정
        cp.showColorPoint(); // 색상과 좌표값 출력
    }
}

// 좌표를 나타내는 Point 클래스 (부모 클래스)
class Point {
    private int x, y; // 점을 구성하는 x, y 좌표값

    // x, y 좌표를 설정하는 메서드
    public void set(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // 현재 좌표를 출력하는 메서드
    public void showPoint() {
        System.out.println("X: " + x + ", Y: " + y);
    }
}

// 색상을 포함한 점을 표현하는 ColorPoint 클래스 (Point 클래스를 상속)
class ColorPoint extends Point {
    private String color; // 점의 색상 저장

    // 색상을 설정하는 메서드
    public void setColor(String color) {
        this.color = color;
    }

    // 색상과 좌표를 출력하는 메서드
    public void showColorPoint() {
        System.out.println("Color: " + color);
        showPoint(); // 부모 클래스의 showPoint() 메서드 호출하여 좌표 출력
    }
}
