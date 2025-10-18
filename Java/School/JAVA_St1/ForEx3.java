import java.util.Scanner;
public class ForEx3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int[] score = new int[5];
		int a = 0;
		for ( int i = 0 ; i < score.length ; i++ ) {
			System.out.printf ( "%d번 학생의 점수 입력 : ", (i+1));
			score[i] = sc.nextInt();
		}
		for ( int i = 0 ; i < score.length-1 ; i++ ) {
			for ( int j = 0 ; j < score.length-1 ; j++ ) {
				if ( score[j] > score[j+1] ) { // score의 j번 방이 j+1번방 보다 클때
					a = score[j]; // a에다가 score j번방에 정수를 저장해둠
					score[j] = score[j+1]; // score j번방을 j+1번방으로 옯김
					score[j+1] = a; // 저장해놨던 변수를 j+1번방으로 옮김
				}
			}
		}
		for ( int i = 0 ; i < score.length ; i++ )
			System.out.printf ( "%d\t", score[i]);
		System.out.printf ( "\n%d(이)가 최고점 입니다.\n%d(이)가 최소점 입니다.", score[score.length-1], score[score.length-score.length] );
	}
}