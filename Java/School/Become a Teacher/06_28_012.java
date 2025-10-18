public class Main {
	public static void main(String[] args) {
		String[] str = new String[]{ "마에스트로", "박수", "울고싶지 않아", "어젯밤", "화이팅 해야지", "아주 NICE"} ;
        	String[] str2 = new String[str.length];
		int a[] = new int[6];
        	for ( int i = 0 ; i < str.length; i++ ) {
            		str2[i] = str[i];
            		int random = (int)(Math.random() * str.length + 1);
            		a[i] = random-1;
            		for (int j = 0 ; j < i ; j++ ) {
                		if ( a[i] == a[j] ) {
                    			i--; break;
                		}
            		}
        	}
        	System.out.print("영희의 셔플 플레이 리스트 : ");
        	for ( int i = 0 ; i < str.length ; i++ ) {
            		str[i] = str2[a[i]];
            		System.out.print(str[i] + ", ");
       		}
    	}
}