/*
// InheritanceEx Ŭ����: ������ ����ϴ� ���� Ŭ����
public class InheritanceEx {
    public static void main(String[] args) {
        // Student ��ü ����
        Student s = new Student();

        // Student Ŭ������ set() �޼��� ȣ��
        s.set();
    }
}

// Person Ŭ���� (�θ� Ŭ����)
class Person {
    private int weight; // private: �ڽ� Ŭ�������� ���� ���� �Ұ���
    int age; // default ���� ������: ���� ��Ű�� ������ ���� ����
    protected int height; // protected: ��ӹ��� Ŭ�������� ���� ����
    public String name; // public: ��𼭵� ���� ����

    // weight ���� �����ϴ� �޼��� (���� ���ٿ�)
    public void setWeight(int weight) {
        this.weight = weight;
    }

    // weight ���� ��ȯ�ϴ� �޼���
    public int getWeight() {
        return weight;
    }
}

// Student Ŭ���� (Person Ŭ������ ��ӹ���)
class Student extends Person {
    // set() �޼���: �θ� Ŭ������ ��� ���� �� ����
    public void set() {
        age = 30; // �θ� Ŭ������ default ��� ���� ���� (���� ��Ű�� ������ ����)
        name = "ȫ�浿"; // �θ� Ŭ������ public ��� ���� ����
        height = 175; // �θ� Ŭ������ protected ��� ���� ����

        // weight = 99; // ���� �߻�! private ����� ���� ���� �Ұ���
        setWeight(99); // private ����� public �޼��带 ���� ���������� ���� ����
    }
}
*/
