import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;

public class suhang2305_03 {
    public static void main(String[] args) {
        String str1 = "국어:97,영어:87,수학:90,과학:77";
        HashMap<String, String> subjectscore = new HashMap<String, String>();
        StringTokenizer st = new StringTokenizer(str1, ",");
        String name[] = new String[4];
        String sc[] = new String[4];

        int i = 0;
        while (st.hasMoreTokens()) {
            String st2[] = st.nextToken().split( ":" );
            subjectscore.put(st2[0], st2[1]);
            name[i] = st2[0];
            sc[i] = st2[1];
            i++;
        }
        int tot = 0;
        double avg = 0;

        System.out.println("과목\t점수");
        System.out.println( "----------------" );
        for( i = 0 ; i < 4 ; i++ ) {
            System.out.printf( "%s\t%s\n", name[i], sc[i]);

            tot += Integer.parseInt(sc[i]);
        }

        avg = tot/4.0;
        System.out.println( "\n합계\t평균" );
        System.out.println( "----------------" );
        System.out.printf("%d\t%.2f", tot, avg);
    }
}
