package javacos;

public class Exam3 {
    public static void main(String[] args) {
        person p1 = new person("Lee Sun Sin", 30);
        person p2 = new person("El Zi Mun Dack", 40);

        p1.showInfo();
        p2.showInfo();
    }
}

class person {
    private String name;
    private int age;

    public person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    } // getName()

    public int getAge() {
        return age;
    } // getAge()

    public void setName(String name) {
        this.name = name;
    } // setName()

    public void setAge(int age) {
        this.age = age;
    } // setAge()

    public void showInfo() {
        System.out.printf("Age : %d, Name : %s\n", age, name);
    } // showInfo()
} // class parson