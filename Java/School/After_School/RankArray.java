public class RankArray {
    public static void main(String[] args) {
        int[][] score = new int[4][5];

        for( int i = 0 ; i < score.length-1 ; i++ ) {
            for( int j = 0 ; j < score[i].length-2 ; j++ ) {
                score[i][j] = (int)( Math.random() * 100 ) + 1;
                score[i][3] += score[i][j];
                score[3][j] += score[i][j];
            }
        }
        
        System.out.println("kor\teng\tmath\tsum\tavg");
        System.out.println("====================================");
        for( int i = 0 ; i < score.length ; i++ ) {
            for( int j = 0 ; j < score[i].length ; j++ ) {
                score[i][4] = score[i][3] / score.length;
                System.out.print( score[i][j] + "\t" );
            }
            System.out.println();
        }
    }
}
