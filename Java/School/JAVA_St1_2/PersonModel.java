//import java.util.Scanner;
//
//public class PersonModel {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        System.out.print("성과 이름을 입력해 주세요");
//        Person Pr = new Person(sc.next(), sc.next());
//        System.out.printf("성 : %s\n이름 : %s\n길이 : %d", Pr.getLastname(), Pr.getFirstname(), Pr.getLength());
//    }
//}
//class Person {
//    String LN;
//    String FN;
//    public Person(String LN, String FN){
//        this.LN = LN;
//        this.FN = FN;
//
//    }
//    String getLastname() {
//        return LN;
//    }
//    String getFirstname() {
//        return FN;
//    }
//    int getLength() {
//        return (int)(FN.length() + LN.length());
//    }
//}