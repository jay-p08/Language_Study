package collectionTest;

public class ForEachTest {
    public static void main(String[] args) {
        int[][] numbers = {{50, 70, 100}, {1, 8, 6}};

        /*for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < numbers[i].length; j++) {
                System.out.print(numbers[i][j] + " ");
            }
        }
        System.out.println(numbers[0][1]);*/
        for (int[] is : numbers) {
            System.out.println(is);
            for (int number : is) {
                System.out.print(number + " ");
            }
        }
    }
}
