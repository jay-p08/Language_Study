package javacos;

public class Exam4 {
    public static void main(String[] args) {
        child c1 = new child("Kim Min Soo", 20);
        child c2 = new child("Park Ji Sun", 30);

        System.out.printf("Name : %s, Age : %d, gender : %d, power : %d\n", c1.getName(), c1.getAge(), c1.getGender(), c1.getPower());
        System.out.printf("Name : %s, Age : %d\n", c2.getName(), c2.getAge());

        c1.walk(); // child class method
        c2.walk(); // child class method
    
    }
}

class parent {
    private int gender;
    private int power;

    parent() {
        this.gender = 1;
        this.power = 100;
    }

    int getGender() {
        return this.gender;
    }

    int getPower() {
        return this.power;
    }

    void walk() {
        System.out.println("walking.");
    }
}

class child extends parent {
    private String name;
    private int age;

    public child(String name, int age) {
        this.name = name;
        this.age = age;
    } // constructor

    public String getName() {
        return name;
    } // getName()

    public int getAge() {
        return age;
    } // getAge()

    void walk() {
        System.out.println("child is walking.");
    } // walk()
}