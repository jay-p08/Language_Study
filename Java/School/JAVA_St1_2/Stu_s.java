/*import java.util.*;
public class Stu_s {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("인원수 입력 : ");
        int p_num = sc.nextInt();
        int num = 0;
        String[] point = new String[]{"국어", "영어", "수학", "JAVA", "학번", "이름", " "};
        double prime = 0;
        char ch = 'a';
        Stu_Class1[] Stu_s = new Stu_Class1[p_num];
        Stu_Class1[] Stu_n = new Stu_Class1[p_num];
        Stu_Class1[] Stu_p = new Stu_Class1[p_num];
        Stu_Class1[] Stu_r = new Stu_Class1[p_num];

        for (int i = 0; i < p_num; i++) {
            Stu_s[i] = new Stu_Class1();
            Stu_n[i] = new Stu_Class1();
            Stu_p[i] = new Stu_Class1();
            Stu_r[i] = new Stu_Class1();
        }

        for (int i = 0; i < p_num; i++)
            Stu_s[i].score[5] = 1;

        for (int i = 0; i < p_num; i++) {
            for (int j = 0, k = 4; j < 2; j++, k++) {
                System.out.printf("%s : ", point[k]);
                Stu_n[i].name[j] = sc.next();
            }
            for (int j = 0; j < 4; j++) {
                do {
                    System.out.printf("%s 점수 : ", point[j]);
                    Stu_s[i].score[j] = sc.nextInt();
                } while (Stu_s[i].score[j] < 0 || Stu_s[i].score[j] > 100);
            }
            for (int j = 0; j < 4; j++)
                Stu_s[i].score[4] += Stu_s[i].score[j];

            Stu_p[i].average = method_Aver(Stu_s[i].score[4]);
            Stu_r[i].rank = method_Point(Stu_p[i].average);
        }
        for (int i = 0; i < p_num - 1; i++)
            for (int j = i + 1; j < p_num; j++) {
                if (Stu_s[i].score[4] < Stu_s[j].score[4]) Stu_s[i].score[5]++;
                else if (Stu_s[i].score[4] > Stu_s[j].score[4]) Stu_s[j].score[5]++;
            }
        System.out.println("1. 입력\n2. 학번\n3. 합계\n4. 정지\n");
        do {
            System.out.print("출력 방법을 선택 하십시오 : ");
            point[point.length - 1] = sc.next();
            if (point[point.length - 1].equals("입력") || point[point.length - 1].equals("학번") || point[point.length - 1].equals("합계") || point[point.length - 1].equals("정지")) {
                if (point[point.length - 1].equals("입력")) {
                    System.out.println("\n입력");
                    for (int i = 0; i < p_num; i++)
                        System.out.printf("\n%-4s %-5s\t%3d %3d %3d %3d %3d %.2f\t%c\t%d\n\n", Stu_n[i].name[0], Stu_n[i].name[1], Stu_s[i].score[0], Stu_s[i].score[1], Stu_s[i].score[2], Stu_s[i].score[3], Stu_s[i].score[4], Stu_p[i].average, Stu_r[i].rank, Stu_s[i].score[5]);
                    System.out.println("=======================================================================");
                } else if (point[point.length - 1].equals("학번")) {
                    for (int i = 0; i < p_num; i++)
                        for (int j = 0; j < p_num - 1; j++) {
                            if (Stu_n[j].name[0].compareTo(Stu_n[j+1].name[0]) > 0) {
                                for (int k = 0; k < 2; k++) {
                                    point[0] = Stu_n[j].name[k];
                                    Stu_n[j].name[k] = Stu_n[j+1].name[k];
                                    Stu_n[j+1].name[k] = point[0];
                                }
                                for (int k = 0; k < 6; k++) {
                                    num = Stu_s[j].score[k];
                                    Stu_s[j].score[k] = Stu_s[j+1].score[k];
                                    Stu_s[j+1].score[k] = num;
                                }
                                prime = Stu_p[j].average;
                                Stu_p[i].average = Stu_p[j + 1].average;
                                Stu_p[j + 1].average = prime;
                                ch = Stu_r[j].rank;
                                Stu_r[j].rank = Stu_r[j + 1].rank;
                                Stu_r[j + 1].rank = ch;
                            }
                        }
                    System.out.println("\n학번");
                    for (int i = 0; i < p_num; i++)
                        System.out.printf("\n%-4s %-5s\t%3d %3d %3d %3d %3d %.2f\t%c\t%d\n\n", Stu_n[i].name[0], Stu_n[i].name[1], Stu_s[i].score[0], Stu_s[i].score[1], Stu_s[i].score[2], Stu_s[i].score[3], Stu_s[i].score[4], Stu_p[i].average, Stu_r[i].rank, Stu_s[i].score[5]);
                    System.out.println("===============================================================================");
                } else if (point[point.length - 1].equals("합계")) {
                    for (int i = 0; i < p_num; i++)
                        for (int j = 0; j < p_num - 1; j++) {
                            if (Stu_s[j].score[4] < Stu_s[j + 1].score[4]) {
                                for (int k = 0; k < 2; k++) {
                                    point[0] = Stu_n[j].name[k];
                                    Stu_n[j].name[k] = Stu_n[j + 1].name[k];
                                    Stu_n[j + 1].name[k] = point[0];
                                }
                                for (int k = 0; k < 6; k++) {
                                    num = Stu_s[j].score[k];
                                    Stu_s[j].score[k] = Stu_s[j + 1].score[k];
                                    Stu_s[j + 1].score[k] = p_num;
                                }
                                prime = Stu_p[j].average;
                                Stu_p[i].average = Stu_p[j + 1].average;
                                Stu_p[j + 1].average = prime;
                                ch = Stu_r[j].rank;
                                Stu_r[j].rank = Stu_r[j + 1].rank;
                                Stu_r[j + 1].rank = ch;
                            }
                        }
                    System.out.println("\n합계");
                    for (int i = 0; i < p_num; i++)
                        System.out.printf("\n%-4s %-5s\t%3d %3d %3d %3d %3d %.2f\t%c\t%d\n\n", Stu_n[i].name[0], Stu_n[i].name[1], Stu_s[i].score[0], Stu_s[i].score[1], Stu_s[i].score[2], Stu_s[i].score[3], Stu_s[i].score[4], Stu_p[i].average, Stu_r[i].rank, Stu_s[i].score[5]);
                    System.out.println("==========================================================");
                } else if (point[point.length - 1].equals("정지")) {
                    System.out.println("\n 프로그램을 정지합니다.\n");
                    break;
                }
            } else {
                System.out.print("다시 입력해 주세요.");
            }
        } while (true);
    }

    public static double method_Aver(int sum) {
        double avar = sum / 4.0;
        return avar;
    }

    public static char method_Point(double aver) {
        char rank;
        switch ((int) aver / 10) {
            case 10:
            case 9:
                rank = 'A';
                break;
            case 8:
                rank = 'B';
                break;
            case 7:
                rank = 'C';
                break;
            case 6:
                rank = 'D';
                break;
            default:
                rank = 'E';
                break;
        }
        return rank;
    }
}
class Stu_Class1 {
        String name[] = new String[2];
        int[] score = new int[6];
        double average;
        char rank;
        void print( int SubJ_N ) {
            System.out.printf("%-4s %-5s \t", name[0], name[1]);
            for (int i = 0 ; i <=SubJ_N; i++) {
                System.out.printf("%3d ", score[i]);
            }
            System.out.printf("%3d ", score[score.length-1]);
            System.out.printf("%.2f\t", average);
        }
}*/