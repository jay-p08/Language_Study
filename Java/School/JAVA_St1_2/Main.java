public class Main {
    public static void main(String[] args) {
        Student Stu = new Student();
        Stu.setName( "ȫ�浿" );
        Stu.setAddress( "����� ���Ǳ� �Ÿ��� 1����" );
        Stu.Print();
    }
}

class Person {
    String name;
    protected String address;

}
class Student extends Person {
    void setName( String name ) {
        this.name = name;
    }
    void setAddress( String address ) {
        this.address = address;
    }
    String getName() {
        return name;
    }
    String getAddress() {
        return address;
    }

    public void Print() {
        System.out.printf( "%s�� %s�� ��� ����.\n", name, address );
    }
}