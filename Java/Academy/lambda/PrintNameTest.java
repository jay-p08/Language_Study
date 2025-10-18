package lambda;

public class PrintNameTest {
    public static void printFullName(PrintName name) {
        System.out.println(name.getFullName("박", "재영"));

    }
    public static void main(String[] args) {
        printFullName((FirstName, LastName) -> FirstName + LastName);
    }
}
