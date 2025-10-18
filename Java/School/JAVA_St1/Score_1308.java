import java.util.*;

public class Score {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("인원수 입력 : ");
        int p_num = sc.nextInt();

        String[] point = new String[]{"국어", "영어", "수학", "JAVA", "학번", "이름", " "};
        Stu_Class1[] originalData = new Stu_Class1[p_num];
        Stu_Class1[] sortedByScore = new Stu_Class1[p_num];
        Stu_Class1[] sortedByID = new Stu_Class1[p_num];
        Stu_Class1[] sortedBySum = new Stu_Class1[p_num];

        for (int i = 0; i < p_num; i++) {
            originalData[i] = new Stu_Class1();
            sortedByScore[i] = new Stu_Class1();
            sortedByID[i] = new Stu_Class1();
            sortedBySum[i] = new Stu_Class1();
        }

        for (int i = 0; i < p_num; i++) {
            // Input student information
            for (int j = 0; j < 2; j++) {
                System.out.printf("%s : ", point[4 + j]);
                originalData[i].name[j] = sc.next();
                sortedByID[i].name[j] = originalData[i].name[j];
            }
            for (int j = 0; j < 4; j++) {
                do {
                    System.out.printf("%s 점수 : ", point[j]);
                    originalData[i].score[j] = sc.nextInt();
                } while (originalData[i].score[j] < 0 || originalData[i].score[j] > 100);
                sortedByScore[i].score[j] = originalData[i].score[j];
                sortedBySum[i].score[j] = originalData[i].score[j];
            }
            originalData[i].score[4] = Arrays.stream(originalData[i].score, 0, 4).sum();
            sortedByScore[i].score[4] = originalData[i].score[4];
            sortedBySum[i].score[4] = originalData[i].score[4];
            originalData[i].average = method_Aver(originalData[i].score[4]);
            sortedByScore[i].average = originalData[i].average;
            sortedBySum[i].average = originalData[i].average;
            originalData[i].rank = method_Point(originalData[i].average);
            sortedByScore[i].rank = originalData[i].rank;
            sortedBySum[i].rank = originalData[i].rank;
        }

        // Calculate ranks based on scores
        for (int i = 0; i < p_num - 1; i++) {
            for (int j = i + 1; j < p_num; j++) {
                if (sortedByScore[i].score[4] < sortedByScore[j].score[4]) {
                    swap(sortedByScore, i, j);
                }
            }
        }

        // Main loop
        System.out.println("1. 입력\n2. 학번\n3. 합계\n4. 정지\n");
        while (true) {
            System.out.print("출력 방법을 선택 하십시오 : ");
            String choice = sc.next();
            if (choice.equals("입력")) {
                printData(originalData, "입력");
            } else if (choice.equals("학번")) {
                Arrays.sort(sortedByID, Comparator.comparing(o -> o.name[0]));
                printData(sortedByID, "학번");
            } else if (choice.equals("합계")) {
                Arrays.sort(sortedBySum, Comparator.comparingInt(o -> -o.score[4]));
                printData(sortedBySum, "합계");
            } else if (choice.equals("정지")) {
                System.out.println("\n 프로그램을 정지합니다.\n");
                break;
            } else {
                System.out.print("다시 입력해 주세요.");
            }
        }
        sc.close();
    }

    public static double method_Aver(int sum) {
        return sum / 4.0;
    }

    public static char method_Point(double aver) {
        switch ((int) aver / 10) {
            case 10:
            case 9: return 'A';
            case 8: return 'B';
            case 7: return 'C';
            case 6: return 'D';
            default: return 'E';
        }
    }

    private static void swap(Stu_Class1[] arr, int i, int j) {
        Stu_Class1 temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void printData(Stu_Class1[] data, String header) {
        System.out.printf("\n%s\n", header);
        for (Stu_Class1 student : data) {
            System.out.printf("%-4s %-5s\t%3d %3d %3d %3d %3d %.2f\t%c\t%d\n",
                    student.name[0], student.name[1], student.score[0], student.score[1], student.score[2], student.score[3], student.score[4], student.average, student.rank, student.score[5]);
        }
        System.out.println("==========================================================");
    }
}

class Stu_Class1 {
    String[] name = new String[2];
    int[] score = new int[6];
    double average;
    char rank;
}
