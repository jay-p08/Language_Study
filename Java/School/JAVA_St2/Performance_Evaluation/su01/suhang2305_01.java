public class suhang2305_01 {
    public static void main(String[] args) {
        Professor teacher = new Professor( "���ӱ���", 41 );
        teacher.print(); teacher.teach();
        TennisPlayer player = new TennisPlayer( "�״Ͻ� ����", 23 );
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
        System.out.println( "���� ���� : " + this.profession );
        System.out.println( "���� ���� : " + this.age );
        walk();
        talk();
    }

    public void walk() {
        System.out.println( "���� �� ����" );
    }

    public void talk() {
        System.out.println("���� �� ����");
    }
    
}
class Professor extends Person {
    public Professor( String profession, int age ) {
        super(profession, age);
    }

    public void teach() {
        System.out.println( "����ĥ �� ����\n" );
    }
}
class TennisPlayer extends Person {
    public TennisPlayer( String profession, int age ) {
        super(profession, age);
    }
    
    public void playTennis() {
        System.out.println( "�״Ͻ� ��⸦ �� �� ����" );
    }
}