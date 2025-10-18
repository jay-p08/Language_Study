package objectTest;

public class EqualsTest2 {
    public static void main(String[] args) {
        Student s1 = new Student(1, "재영", 17);

        if (s1.equals(new Student(1, "재영", 17))) {
            System.out.println("대여 완료");
        } else {
            System.out.println("도난 신고");
        }
    }
}
class Student {
    private int id;
    private String name;
    private int age;

    public Student() {;}
    public Student(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj instanceof Student) {
            Student s = (Student) obj;
            if (s.getId() == this.getId()) {
                return true;
            }
        }
        return false;
    }
}