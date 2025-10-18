//public class MainClass {
//    public static void main(String[] args) {
//        Leader hong = new Leader("홍길동", "30130", true);
//        Leader Park = new Leader("박재영", "1308", false);
//        hong.isLeader();
//        Park.isLeader();
//    }
//}
//
//class Student {
//    String name;
//    String hakbun;
//    String phone;
//    String juso;
//    String major;
//
//    public Student() { }
//    public Student(String name, String hakbun) {
//        this.name = name;
//        this.hakbun = hakbun;
//    }
//
//    public void study() {
//        System.out.println("공부하다.");
//    }
//    public void eat() {
//        System.out.println("식사하다.");
//    }
//    public void test() {
//        System.out.println("시험보다.");
//    }
//    public void extra_act() {
//        System.out.println("동아리 활동하다.");
//    }
//}
//
//class Leader extends Student {
//    boolean isLeader;
//    public Leader(String name, String hakbun, boolean isLeader) {
//        super(name, hakbun);
//        this.isLeader = isLeader;
//    }
//
//    public void isLeader() {
//        if ( this.isLeader ) {
//            System.out.printf("%s은 학급회장이다.\n", this.name);
//        } else {
//            System.out.printf("%s은 학급회장이 아니다.\n", this.name);
//        }
//    }
//}