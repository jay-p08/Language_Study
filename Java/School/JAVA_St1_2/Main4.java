import java.util.Scanner;

public class Main4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int maxnumber = 20;
        Student[] roster = new Student[maxnumber];
        int number = 0;
        String name = "";
        int score;
        int level;

        do {
            System.out.print("�л��� ������ �Է��ϼ���(�кλ�=1, ���п���=2): ");
            level = scan.nextInt();
            if ( level == 1 ) {
                roster[number] = new UndergraduateStudent( name );
            } else {
                roster[number] = new GraduateStudent( name );
            }
            System.out.print("�л��� �̸��� �Է��ϼ���. : ");
            name = scan.next();
            roster[number].seName( name );
            System.out.print("�л��� ������ �Է��ϼ���. : ");
            score = scan.nextInt();
            roster[number].seScore( score );

            roster[number].computeGrade();
            
            System.out.print("ó���� �л����� �� �ֽ��ϱ�?( �� Ȥ�� �ƴϿ�)");
            if (scan.next().equals("�ƴϿ�")) break;

            number++;
        } while (true);

        System.out.println("�Ҽ�      �̸�      ����      ����");
        for( int i = 0 ; i < number+1 ; i++ ) {
            roster[i].print();
        }

        scan.close();
    }
}

abstract class Student {
    protected String name;
    protected int score;
    protected String grade;

    public Student(String name) {
        seName(name);
    }

    void seName(String name) {
        this.name = name;
    }

    void seScore(int score) {
        this.score = score;
    }

    String getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    String getGrade() {
        return grade;
    }

    abstract void computeGrade();

    void print() {
        System.out.printf("");
    }
}

class UndergraduateStudent extends Student {
    public UndergraduateStudent(String name) {
        super(name);
    }

    void computeGrade() {
        if (score >= 70)
            this.grade = "���";
        else
            this.grade = "����";
    }

    void print() {
        System.out.printf("�к�    %3s      %3d       %2s\n", getName(), getScore(), getGrade());
    }
}

class GraduateStudent extends Student {
    public GraduateStudent(String name) {
        super(name);
    }

    void computeGrade() {
        if (score >= 80)
            this.grade = "���";
        else
            this.grade = "����";
    }

    void print() {
        System.out.printf("���п�    %3s   %3d       %2s\n", getName(), getScore(), getGrade());
    }
}