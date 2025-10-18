// SuperEx Ŭ����: ������ ����ϴ� ���� Ŭ����
public class SuperEx {
    public static void main(String[] args) {
        // ColorPoint1 ��ü�� �����ϸ鼭 (x=5, y=6, color="Blue") ���� ����
        ColorPoint1 cp = new ColorPoint1(5, 6, "Blue");

        // ������ ��ü�� ����� ��ǥ�� ����ϴ� �޼��� ȣ��
        cp.showColorPoint();
    }
}

// ��ǥ�� �����ϴ� Point1 Ŭ���� (�θ� Ŭ����)
class Point1 {
    private int x, y; // x, y ��ǥ���� �����ϴ� ����

    // �⺻ ������: x�� y�� 0���� �ʱ�ȭ
    public Point1() {
        this.x = this.y = 0;
    }

    // �Ű������� �ִ� ������: ���޹��� ������ x, y �ʱ�ȭ
    public Point1(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // ��ǥ ���� ����ϴ� �޼���
    public void showPoint() {
        System.out.println(this.x + ", " + this.y);
    }
}

// ������ ������ ��ǥ Ŭ���� (Point1�� ��ӹ���)
class ColorPoint1 extends Point1 {
    private String color; // ������ �����ϴ� ����

    // ������: x, y ��ǥ�� ������ �޾� �ʱ�ȭ
    public ColorPoint1(int x, int y, String color) {
        super(x, y); // �θ� Ŭ����(Point1)�� �����ڸ� ȣ���Ͽ� x, y ���� ����
        this.color = color; // ���� �� ����
    }

    // ����� ��ǥ�� ����ϴ� �޼���
    public void showColorPoint() {
        System.out.println(this.color); // ���� ���
        showPoint(); // �θ� Ŭ������ showPoint() �޼��带 ȣ���Ͽ� ��ǥ ���
    }
}
