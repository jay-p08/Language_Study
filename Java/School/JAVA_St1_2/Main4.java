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
            System.out.print("학생의 수준을 입력하세요(학부생=1, 대학원생=2): ");
            level = scan.nextInt();
            if ( level == 1 ) {
                roster[number] = new UndergraduateStudent( name );
            } else {
                roster[number] = new GraduateStudent( name );
            }
            System.out.print("학생의 이름을 입력하세요. : ");
            name = scan.next();
            roster[number].seName( name );
            System.out.print("학생의 점수를 입력하세요. : ");
            score = scan.nextInt();
            roster[number].seScore( score );

            roster[number].computeGrade();
            
            System.out.print("처리할 학생들이 더 있습니까?( 예 혹은 아니오)");
            if (scan.next().equals("아니오")) break;

            number++;
        } while (true);

        System.out.println("소속      이름      점수      학점");
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
            this.grade = "통과";
        else
            this.grade = "낙제";
    }

    void print() {
        System.out.printf("학부    %3s      %3d       %2s\n", getName(), getScore(), getGrade());
    }
}

class GraduateStudent extends Student {
    public GraduateStudent(String name) {
        super(name);
    }

    void computeGrade() {
        if (score >= 80)
            this.grade = "통과";
        else
            this.grade = "낙제";
    }

    void print() {
        System.out.printf("대학원    %3s   %3d       %2s\n", getName(), getScore(), getGrade());
    }
}