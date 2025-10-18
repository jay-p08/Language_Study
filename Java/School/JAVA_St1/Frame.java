package javaStudy;
import java.awt.*;
import javax.swing.*;
public class TestFrame extends JFrame {
	public TestFrame() {
		setTitle ( "프레임의 기초" );
		setDefaultCloseOperation ( JFrame.EXIT_ON_CLOSE );
		setSize ( 500, 300 );

		Container CTP = getContentPane();
		CTP.setLayout(null);

		JLabel Label = new JLabel ( "레이블 기초" );
		Label.setBounds ( 182, 133, 124, 15 );
		CTP.add ( Label );

		JButton button = new JButton ( "버튼 기초" );
		button.setBounds ( 182, 59, 110, 23 );
		CTP.add ( button );
		
		setVisible ( true );
	}
	public static void main ( String [ ] args ) {
		TestFrame frame = new TestFrame();
	}
}