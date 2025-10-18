// 오버라이딩(메서드 재정의) 예제
public class Overriding {
    public static void main( String[] args ) {
        Weapon weapon; // Weapon 타입의 참조 변수 선언

        // Weapon 객체 생성 및 fire() 호출
        weapon = new Weapon(); 
        System.out.printf( "기본 무기의 살상 능력은 %d\n", weapon.fire() ); // 기본 무기 fire() 호출

        // Cannon 객체 생성 및 fire() 호출
        weapon = new Cannon(); 
        System.out.printf( "대포의 살상 능력은 %d\n", weapon.fire() ); // 대포 fire() 호출
    }
}

// 무기 클래스 (기본 클래스)
class Weapon {
    // 기본 fire() 메서드: 무기의 살상 능력은 기본적으로 1
    protected int fire() {
        return 1; // 기본 무기에서 한명만 살상
    }
}

// 대포 클래스 (Weapon을 상속받음)
class Cannon extends Weapon {
    // fire() 메서드를 오버라이딩하여 대포의 살상 능력을 10으로 변경
    @Override
    protected int fire() {
        return 10; // 대포는 한 번에 10명을 살상
    }
}
