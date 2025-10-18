import java.io.*;
import java.util.*;

class sungDataRWExam {
    int length;
    sungData[] sD = new sungData[10];
    public void writingData( String fname, boolean append ) throws IOException {
        FileWriter fw = null;
        BufferedWriter bw = null;
        try {
            fw = new FileWriter( new File( fname ) );
            bw = new BufferedWriter( fw );
            for( int i = 0 ; i < length ; i ++ ) {
                bw.write( sD[i].name + "\t" + sD[i].address + "\t" + sD[i].math + "\t" + sD[i].english + "\t" + sD[i].total + "\t" + sD[i].avg );
                bw.newLine();
            }
            bw.close();
            fw.close();
        } catch ( FileNotFoundException e ) {
            System.out.println("잘못된 파일");
        }
    }
    public void readingData( String fname ) throws IOException {
        try {
            String csvStr = "";
            String tmpStr = "";
            FileReader fr = new FileReader( new File( fname ) );
            BufferedReader br = new BufferedReader( fr );
            do {
                tmpStr = br.readLine();
                if( tmpStr != null ) {
                    csvStr += tmpStr + " ";
                }
            } while( tmpStr != null );
            StringTokenizer parse = new StringTokenizer( csvStr, " " );
            length = parse.countTokens()/4;
            for( int i = 0 ; i < length ; i ++ ) {
                sD[i] = new sungData();
                sD[i].name = parse.nextToken();
                sD[i].address = parse.nextToken();
                sD[i].math = Double.valueOf( parse.nextToken() ).doubleValue();
                sD[i].english = Double.valueOf( parse.nextToken() ).doubleValue();
                sD[i].total = sD[i].math + sD[i].english;
                sD[i].avg = sD[i].total / 2.0;
            }
        } catch ( FileNotFoundException e ) {
            System.out.println("파일 못 찾음");
        }
    }
}
class WritingDatasMain {
    public static void main( String[] args ) {
        sungDataRWExam wd = new sungDataRWExam();
        try {
            wd.readingData("writed.txt");
            wd.writingData("writing.txt", false);
        } catch ( IOException e ) {
            e.printStackTrace();
        }
    }
}

class sungData {
    String name;
    String address;
    double math;
    double english;
    double total;
    double avg;
}