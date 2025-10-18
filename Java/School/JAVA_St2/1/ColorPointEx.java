// ColorPointEx Ŭ����: ���α׷� ������ ����ϴ� ���� Ŭ����
public class ColorPointEx {
    public static void main(String[] args) {
        // Point ��ü ����
        Point p = new Point();
        p.set(1, 2); // ��ǥ�� (1,2) ����
        p.showPoint(); // ������ ��ǥ�� ���

        // ColorPoint ��ü ����
        ColorPoint cp = new ColorPoint();
        cp.set(3, 4); // ��ǥ�� (3,4) ���� (�θ� Ŭ���� �޼��� ���)
        cp.setColor("red"); // ������ "red"�� ����
        cp.showColorPoint(); // ����� ��ǥ�� ���
    }
}

// ��ǥ�� ��Ÿ���� Point Ŭ���� (�θ� Ŭ����)
class Point {
    private int x, y; // ���� �����ϴ� x, y ��ǥ��

    // x, y ��ǥ�� �����ϴ� �޼���
    public void set(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // ���� ��ǥ�� ����ϴ� �޼���
    public void showPoint() {
        System.out.println("X: " + x + ", Y: " + y);
    }
}

// ������ ������ ���� ǥ���ϴ� ColorPoint Ŭ���� (Point Ŭ������ ���)
class ColorPoint extends Point {
    private String color; // ���� ���� ����

    // ������ �����ϴ� �޼���
    public void setColor(String color) {
        this.color = color;
    }

    // ����� ��ǥ�� ����ϴ� �޼���
    public void showColorPoint() {
        System.out.println("Color: " + color);
        showPoint(); // �θ� Ŭ������ showPoint() �޼��� ȣ���Ͽ� ��ǥ ���
    }
}
