import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JSpinner;
import javax.swing.JSplitPane;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SpinnerDateModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JOptionPane;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

class ReservationPanel extends JPanel {
    private JTextField nameField;
    private JTextField phoneField;
    private JButton reserveButton;
    private JButton editButton;
    private JButton deleteButton;
    private JComboBox<String> doctorCombo;
    private JComboBox<String> departmentCombo;
    private JSpinner dateSpinner;
    private JPanel inputPanel;
    private ReservationManager manager;
    private DefaultListModel<String> listModel;
    private JList<String> reservationList;
    private int selectedIndex = -1;

    public ReservationPanel() {
        manager = new ReservationManager();
        setLayout( new BorderLayout( 10, 10 ) );
        setBorder( BorderFactory.createEmptyBorder( 10, 10, 10, 10 ) );
        inputPanel = new JPanel( new BorderLayout( 5, 5 ) );
        JPanel fieldsPanel = new JPanel( new FlowLayout( FlowLayout.LEFT, 5, 5 ) );

        fieldsPanel.add( new JLabel( "�̸� : " ) );
        nameField = new JTextField( 10 );
        fieldsPanel.add( nameField );

        fieldsPanel.add( new JLabel( "���� ��¥ : " ) );
        SpinnerDateModel dateModel = new SpinnerDateModel( new Date(), null, null, java.util.Calendar.DAY_OF_MONTH );
        dateSpinner = new JSpinner( dateModel );
        JSpinner.DateEditor dateEditor = new JSpinner.DateEditor( dateSpinner, "yyyy-mm-dd" );
        dateSpinner.setEditor( dateEditor );
        fieldsPanel.add( dateSpinner );

        fieldsPanel.add( new JLabel( "���ΰ��� : " ) );
        String[] departments = { "����", "����ΰ�", "�Ȱ�", "�����ܰ�", "�̺����İ�" };
        departmentCombo = new JComboBox<>( departments );
        fieldsPanel.add( departmentCombo );

        fieldsPanel.add( new JLabel( "�ǻ�" ) );
        doctorCombo = new JComboBox<>();
        fieldsPanel.add( doctorCombo );

        JPanel buttonPanel = new JPanel( new FlowLayout( FlowLayout.LEFT, 5, 5 ) );
        reserveButton = new JButton( "����" );
        editButton = new JButton( "����" );
        deleteButton = new JButton( "����" );
        buttonPanel.add( reserveButton );
        buttonPanel.add( editButton );
        buttonPanel.add( deleteButton );

        inputPanel.add( fieldsPanel, BorderLayout.NORTH );
        inputPanel.add( buttonPanel, BorderLayout.SOUTH );

        departmentCombo.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                String selectedDept = (String)departmentCombo.getSelectedItem();
                if ( selectedDept != null ) {
                    doctorCombo.removeAllItems();

                    if ( selectedDept.equals( "����" ) ) {
                        doctorCombo.addItem( "��ö��" );
                        doctorCombo.addItem( "�̿���" );
                    } // if
                    else if ( selectedDept.equals( "����ΰ�" ) ) {
                        doctorCombo.addItem( "�ڹμ�" );
                        doctorCombo.addItem( "������" );
                    } // else if
                    else if ( selectedDept.equals( "�Ȱ�" ) ) {
                        doctorCombo.addItem( "����ȣ" );
                        doctorCombo.addItem( "������" );
                    } // else if
                    else if ( selectedDept.equals( "�����ܰ�" ) ) {
                        doctorCombo.addItem( "�嵿��" );
                        doctorCombo.addItem( "���ر�" );
                    } // else if
                    else if ( selectedDept.equals( "�̺����İ�" ) ) {
                        doctorCombo.addItem( "���ؿ�" );
                        doctorCombo.addItem( "���¸�" );
                    } // else if
                    doctorCombo.revalidate();
                    doctorCombo.repaint();

                    listModel = new DefaultListModel<>();
                    reservationList = new JList<>( listModel );
                    reservationList.setSelectionMode( ListSelectionModel.SINGLE_SELECTION );
                    JScrollPane scrollPane = new JScrollPane( reservationList );
                    scrollPane.setPreferredSize( new Dimension( 500, 200 ) );

                    JPanel listPanel = new JPanel( new BorderLayout() );
                    listPanel.add( new JLabel( "���� ���" ), BorderLayout.NORTH );
                    listPanel.add( scrollPane, BorderLayout.CENTER );

                    JSplitPane splitPane = new JSplitPane( JSplitPane.VERTICAL_SPLIT, inputPanel, listPanel );
                    splitPane.setResizeWeight( 0.3 );
                    splitPane.setContinuousLayout( true );
                    add( splitPane( new BorderLayout() ) );

                    reserveButton.addActionListener( new ActionListener() {
                        public void actionPerformed( ActionEvent e ) {
                            String name = nameField.getText().trim();
                            String phone = phoneField.getText().trim();
                            if ( name.isEmpty() || phone.isEmpty() || dateSpinner.getValue() == null || doctorCombo.getSelectedItem() == null ) {
                                JOptionPane.showMessageDialog( ReservationPanel.this, "��� �׸��� �Է¹ٶ�" );
                                return;
                            } // if

                            String dateStr = new SimpleDateFormat( "yyyy-MM-dd" ).format( ( Date ) dateSpinner.getValue() );
                            String doctor = ( String )doctorCombo.getSelectedItem();
                            String department = ( String )departmentCombo.getSelectedItem();

                            Patient patient = new Patient( name, phone, dateStr, doctor, department );

                            manager.addReservation( patient );  
                        } // actionPerformed()
                    }); // addActionListener

                    listModel.clear();
                    for ( Patient p : manager.getReservations() ) {
                        String display = String.format( "%s | %s | %s | %s | %s", p.getDepartment(), p.getName(), p.getPhone(), p.getDate(), p.getDoctor() );
                        listModel.addElement( display );
                    } // for

                    nameField.setText( "" );
                    phoneField.setText( "" );
                    dateSpinner.setValue( new Date() );
                    departmentCombo.setSelectedIndex( 0 );

                    reservationList.clearSelection();
                    selectedIndex = -1;
                    JOptionPane.showConfirmDialog( ReservationPanel.this, "������ �Ϸ�Ǿ����ϴ�." );

                    reservationList.addListSelectionListener( new ListSelectionListener() {
                        public void valueChanged( ListSelectionEvent e ) {
                            if ( !e.getValueIsAdjusting() ) {
                                selectedIndex = reservationList.getSelectedIndex();
                                if ( selectedIndex >= 0 ) {
                                    Patient patient = manager.getReservations().get( selectedIndex );
                                    nameField.setText( patient.getName() );
                                    phoneField.setText( patient.getPhone() );
                                    departmentCombo.setSelectedItem( patient.getDepartment() );
                                    doctorCombo.removeAllItems();
                                    String dept = patient.getDepartment();
                                } // if
                            } // if
                            doctorCombo.removeAllItems();
                            String dept = patient.getDepartment();

                            if ( selectedDept.equals( "����" ) ) {
                                doctorCombo.addItem( "��ö��" );
                                doctorCombo.addItem( "�̿���" );
                            } // if
                            else if ( selectedDept.equals( "����ΰ�" ) ) {
                                doctorCombo.addItem( "�ڹμ�" );
                                doctorCombo.addItem( "������" );
                            } // else if
                            else if ( selectedDept.equals( "�Ȱ�" ) ) {
                                doctorCombo.addItem( "����ȣ" );
                                doctorCombo.addItem( "������" );
                            } // else if
                            else if ( selectedDept.equals( "�����ܰ�" ) ) {
                                doctorCombo.addItem( "�嵿��" );
                                doctorCombo.addItem( "���ر�" );
                            } // else if
                            else if ( selectedDept.equals( "�̺����İ�" ) ) {
                                doctorCombo.addItem( "���ؿ�" );
                                doctorCombo.addItem( "���¸�" );
                            } // else if
                            doctorCombo.setSelectedItem( patient.getDoctor() );
                        } // valueChanged()
                    }); // addListSelectionListener()

                    
                } // if
            } // actionPerformed()
        }); // addActionListener

    } // ReservationPanel

    
} // Class ReservationPanel
