public class suhang2305_01 {
    public static void main(String[] args) {
        Professor teacher = new Professor( "전임교수", 41 );
        teacher.print(); teacher.teach();
        TennisPlayer player = new TennisPlayer( "테니스 선수", 23 );
        player.print(); player.playTennis();

    }
}

class Person {
    String profession;
    int age;

    Person( String profession, int age ) {
        this.profession = profession;
        this.age = age;
    }

    public void print( ) {
        System.out.println( "나의 직업 : " + this.profession );
        System.out.println( "나의 나이 : " + this.age );
        walk();
        talk();
    }

    public void walk() {
        System.out.println( "걸을 수 있음" );
    }

    public void talk() {
        System.out.println("말할 수 있음");
    }
    
}
class Professor extends Person {
    public Professor( String profession, int age ) {
        super(profession, age);
    }

    public void teach() {
        System.out.println( "가르칠 수 있음\n" );
    }
}
class TennisPlayer extends Person {
    public TennisPlayer( String profession, int age ) {
        super(profession, age);
    }
    
    public void playTennis() {
        System.out.println( "테니스 경기를 할 수 있음" );
    }
}