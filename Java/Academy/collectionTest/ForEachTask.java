package collectionTest;

public class ForEachTask {
    public static void main(String[] args) {
        int[][] scores = {{100, 80, 65}, {40, 77, 30}};
        int sum = 0;
        double average = 0;
        for ( int[] is : scores ) {
            sum = 0;
            for (int score : is ) {
                sum += score;
            }
//            average = (double)sum / is.length;
            average = Double.parseDouble(String.format("%.2f", (double)sum / is.length));
            System.out.println(sum);
            System.out.println(average);
        }
    }
}
