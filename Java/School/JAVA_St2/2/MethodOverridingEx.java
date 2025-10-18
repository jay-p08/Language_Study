// �޼ҵ� �������̵� ����
public class MethodOverridingEx {
    
    // ���� �޼��� paint() ����: �Ű������� Shape Ÿ���� ��ü�� ����
    static void paint( Shape p ) {
        p.draw(); // p�� ����Ű�� ��ü ������ �������̵��� draw() ȣ�� (���� ���ε�)
    }

    public static void main( String[] args ) {
        // Shape Ŭ������ ��ӹ��� ���� ��ü ���� �� paint() ȣ��
        Line line = new Line(); // Line ��ü ����
        paint( line );         // Line�� draw() ����
        paint( new Shape() );  // Shape�� draw() ����
        paint( new Line() );   // Line�� draw() ����
        paint( new Rect() );   // Rect�� draw() ����
        paint( new Circle() ); // Circle�� draw() ����
    }
}

// �θ� Ŭ���� (���� Ŭ����)
class Shape {
    public Shape next; // ���� ��ü�� ����Ű�� ���� (���� ����Ʈ�� ������ ����)
    
    public Shape() { 
        next = null; // �����ڿ��� next�� null�� �ʱ�ȭ
    }

    // �������̵��� �޼���
    public void draw() {
        System.out.println( "Shape" ); // �⺻������ "Shape" ���
    }
}

// �ڽ� Ŭ���� (Shape�� ��ӹ���)
class Line extends Shape {
    // �θ� Ŭ������ draw() �޼��带 �������̵�
    public void draw() {
        System.out.println( "Line" ); // "Line" ���
    }
}

// �ڽ� Ŭ���� (Shape�� ��ӹ���)
class Rect extends Shape {
    // �θ� Ŭ������ draw() �޼��带 �������̵�
    public void draw() {
        System.out.println( "Rect" ); // "Rect" ���
    }
}

// �ڽ� Ŭ���� (Shape�� ��ӹ���)
class Circle extends Shape {
    // �θ� Ŭ������ draw() �޼��带 �������̵�
    public void draw() {
        System.out.println( "Circle" ); // "Circle" ���
    }
}
