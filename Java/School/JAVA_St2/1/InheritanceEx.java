/*
// InheritanceEx 클래스: 실행을 담당하는 메인 클래스
public class InheritanceEx {
    public static void main(String[] args) {
        // Student 객체 생성
        Student s = new Student();

        // Student 클래스의 set() 메서드 호출
        s.set();
    }
}

// Person 클래스 (부모 클래스)
class Person {
    private int weight; // private: 자식 클래스에서 직접 접근 불가능
    int age; // default 접근 제어자: 같은 패키지 내에서 접근 가능
    protected int height; // protected: 상속받은 클래스에서 접근 가능
    public String name; // public: 어디서든 접근 가능

    // weight 값을 설정하는 메서드 (간접 접근용)
    public void setWeight(int weight) {
        this.weight = weight;
    }

    // weight 값을 반환하는 메서드
    public int getWeight() {
        return weight;
    }
}

// Student 클래스 (Person 클래스를 상속받음)
class Student extends Person {
    // set() 메서드: 부모 클래스의 멤버 변수 값 설정
    public void set() {
        age = 30; // 부모 클래스의 default 멤버 접근 가능 (같은 패키지 내에서 가능)
        name = "홍길동"; // 부모 클래스의 public 멤버 접근 가능
        height = 175; // 부모 클래스의 protected 멤버 접근 가능

        // weight = 99; // 오류 발생! private 멤버는 직접 접근 불가능
        setWeight(99); // private 멤버는 public 메서드를 통해 간접적으로 설정 가능
    }
}
*/
