// 메소드 오버라이딩 예제
public class MethodOverridingEx {
    
    // 정적 메서드 paint() 정의: 매개변수로 Shape 타입의 객체를 받음
    static void paint( Shape p ) {
        p.draw(); // p가 가리키는 객체 내에서 오버라이딩된 draw() 호출 (동적 바인딩)
    }

    public static void main( String[] args ) {
        // Shape 클래스를 상속받은 여러 객체 생성 및 paint() 호출
        Line line = new Line(); // Line 객체 생성
        paint( line );         // Line의 draw() 실행
        paint( new Shape() );  // Shape의 draw() 실행
        paint( new Line() );   // Line의 draw() 실행
        paint( new Rect() );   // Rect의 draw() 실행
        paint( new Circle() ); // Circle의 draw() 실행
    }
}

// 부모 클래스 (슈퍼 클래스)
class Shape {
    public Shape next; // 다음 객체를 가리키는 변수 (연결 리스트와 유사한 구조)
    
    public Shape() { 
        next = null; // 생성자에서 next를 null로 초기화
    }

    // 오버라이딩될 메서드
    public void draw() {
        System.out.println( "Shape" ); // 기본적으로 "Shape" 출력
    }
}

// 자식 클래스 (Shape을 상속받음)
class Line extends Shape {
    // 부모 클래스의 draw() 메서드를 오버라이딩
    public void draw() {
        System.out.println( "Line" ); // "Line" 출력
    }
}

// 자식 클래스 (Shape을 상속받음)
class Rect extends Shape {
    // 부모 클래스의 draw() 메서드를 오버라이딩
    public void draw() {
        System.out.println( "Rect" ); // "Rect" 출력
    }
}

// 자식 클래스 (Shape을 상속받음)
class Circle extends Shape {
    // 부모 클래스의 draw() 메서드를 오버라이딩
    public void draw() {
        System.out.println( "Circle" ); // "Circle" 출력
    }
}
