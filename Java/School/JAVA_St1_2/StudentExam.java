//import java.sql.SQLOutput;
//
//public class StudentExam {
//        public static void main(String[] args) {
//            Student Kim = new Student("김현우");
//            Student jang = new Student("장민재", 3);
//
//            Kim.SetGrade(2);
//
//            System.out.printf("%s는 %d학년 입니다\n", Kim.GetName(), Kim.GetGrade());
//            System.out.printf("%s는 %d학년 입니다\n", jang.GetName(), jang.GetGrade());
//
//            Kim.SetGrade(5);
//
//            System.out.printf("%s는 %d학년 입니다\n", Kim.GetName(), Kim.GetGrade());
//        }
//    }
//    class Student {
//        private String name;
//        private int grade;
//        public Student() {}
//        public Student(String name) {
//            this.name = name;
//        }
//        public Student(String name, int grade) {
//            this(name);
//            this.grade = grade;
//        }
//
//        void SetGrade(int grade) {
//            if (grade >= 1 && grade <= 3) {
//                this.grade = grade;
//            } else {
//                System.out.println("오류오류오류오류");
//            }
//        }
//
//        String GetName() {
//            return this.name;
//        }
//
//        int GetGrade() {
//            return this.grade;
//        }
//
//    }