package javaStudy;
import java.awt.*;
import javax.swing.*;
public class TestFrame extends JFrame {
	public TestFrame() {
		setTitle ( "�������� ����" );
		setDefaultCloseOperation ( JFrame.EXIT_ON_CLOSE );
		setSize ( 500, 300 );

		Container CTP = getContentPane();
		CTP.setLayout(null);

		JLabel Label = new JLabel ( "���̺� ����" );
		Label.setBounds ( 182, 133, 124, 15 );
		CTP.add ( Label );

		JButton button = new JButton ( "��ư ����" );
		button.setBounds ( 182, 59, 110, 23 );
		CTP.add ( button );
		
		setVisible ( true );
	}
	public static void main ( String [ ] args ) {
		TestFrame frame = new TestFrame();
	}
}