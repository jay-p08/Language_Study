package 병원;

import javax.swing.JFrame;
import javax.swing.WindowConstants;

public class Hospital extends JFrame {
    public Hospital() {
        setTitle( "병원 예약 시스템" );
        setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );
        setLocationRelativeTo( null );
        setVisible( true );
    } // Hospital

    public static void main( String[] args ) {
        new JFrame();
    } // main()
} // Class Hospital
