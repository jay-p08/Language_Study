/*
import java.util.*;

public class dataValueExam {
    public static void main(String[] args) {
        String line;
        String temStr = "hong-용산구-10.5-20.5";
        StringTokenizer parse = new StringTokenizer(temStr);

        String name;
        String address;
        double math;
        double english;
        double total;
        double avg;

        name = parse.nextToken("-");
        address = parse.nextToken("-");
        math = Double.valueOf(parse.nextToken()).doubleValue();
        english = Double.valueOf(parse.nextToken()).doubleValue();
        total = math + english;
        avg = total / 2.0;

        System.out.printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f", name, address, math, english, total, avg);
    }
}
*/
