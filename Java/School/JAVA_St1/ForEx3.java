import java.util.Scanner;
public class ForEx3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		int[] score = new int[5];
		int a = 0;
		for ( int i = 0 ; i < score.length ; i++ ) {
			System.out.printf ( "%d�� �л��� ���� �Է� : ", (i+1));
			score[i] = sc.nextInt();
		}
		for ( int i = 0 ; i < score.length-1 ; i++ ) {
			for ( int j = 0 ; j < score.length-1 ; j++ ) {
				if ( score[j] > score[j+1] ) { // score�� j�� ���� j+1���� ���� Ŭ��
					a = score[j]; // a���ٰ� score j���濡 ������ �����ص�
					score[j] = score[j+1]; // score j������ j+1�������� ����
					score[j+1] = a; // �����س��� ������ j+1�������� �ű�
				}
			}
		}
		for ( int i = 0 ; i < score.length ; i++ )
			System.out.printf ( "%d\t", score[i]);
		System.out.printf ( "\n%d(��)�� �ְ��� �Դϴ�.\n%d(��)�� �ּ��� �Դϴ�.", score[score.length-1], score[score.length-score.length] );
	}
}