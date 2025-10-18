public class Main {
    public static void main(String[] args) {
        Student Stu = new Student();
        Stu.setName( "홍길동" );
        Stu.setAddress( "서울시 관악구 신림동 1번지" );
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
        System.out.printf( "%s은 %s에 살고 있음.\n", name, address );
    }
}