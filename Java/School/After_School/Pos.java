import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Desktop.Action;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class Pos extends JFrame {
    private DefaultListModel<String> cartModel;
    private JList<String> cartList;
    private JLabel totalLabel;
    private JPanel centerJPanel;
    private int total = 0;

    JTextField nameInput, priceInput;
    JButton addProductButton, removeProductButton;

    public Pos() {
        setTitle( "mirim Pos" );
        setSize( 600, 400 );
        setDefaultCloseOperation( EXIT_ON_CLOSE );
        setLocationRelativeTo( null );
        setLayout( new BorderLayout() );

        JPanel productPanel = new JPanel( new GridLayout( 3, 2, 10, 10 ));
        productPanel.setBorder( null );

        String[][] products = { { "사과", "2000" },
                                { "포도", "4000" },
                                { "담배", "5500" },
                                { "콜라", "2200" },
                                { "소주", "3300" },
                                { "껌", "500" } };
        
        for( int i = 0 ; i < products.length ; i++ ) {
            String productName = products[i][0];
            int price = Integer.parseInt( products[i][1] );

            JButton btn = new JButton( productName + " : " + price + "원");
            btn.addActionListener(new ActionListener() {
                public void actionPerformed( ActionEvent e ) {
                    cartModel.addElement( productName + " : " + price + "원" );
                }
            });
            productPanel.add( btn );
        } // for
        centerJPanel.add( productPanel );
        JPanel cartPanel = new JPanel( new BorderLayout() );
        cartModel = new DefaultListModel<String>();
        cartList = new JList<>( cartModel );

        cartPanel.add( new JScrollPane( cartList ), BorderLayout.CENTER );
        totalLabel = new JLabel( "Total : " + total + "won" );
        cartPanel.add( totalLabel, BorderLayout.SOUTH );
        centerJPanel.add(cartPanel);
        JPanel btnPanel = new JPanel( new FlowLayout() );

        JButton payButton = new JButton( "결제" );
        payButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                if( cartModel.isEmpty() ) {
                    JOptionPane.showMessageDialog( null, "장바구니가 비어있어요" );
                } // if
                else {
                    JOptionPane.showMessageDialog( null, "결제완료" + total + "원" );
                    cartModel.clear();
                    total = 0;
                    totalLabel.setText( "total 0won" );
                } // else
            } // actionPerformed
        }); // addActionListener
        btnPanel.add( payButton );

        addProductButton = new JButton( "상품등록" );
        removeProductButton = new JButton( "상품삭제" );
        JLabel admin = new JLabel( "admin : " );
        btnPanel.add( admin );
        btnPanel.add( addProductButton );
        btnPanel.add( removeProductButton );
        nameInput = new JTextField( 10 );
        priceInput = new JTextField( 10 );

        JPanel inputPanel = new JPanel( new BorderLayout() );
        inputPanel.add( new JLabel( "상품명 : " ) );
        inputPanel.add( nameInput );
        inputPanel.add( new JLabel( "가격 : " ) );
        inputPanel.add( priceInput );

        JButton addItemButton = new JButton( "새상품등록" );
        inputPanel.add( addItemButton );

        btnPanel.add( btnPanel, BorderLayout.NORTH );
        JPanel btnAll = new JPanel( new BorderLayout() );
        btnAll.add( btnPanel, BorderLayout.SOUTH );

        addProductButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                String name = nameInput.getText();
                String price = priceInput.getText();

                if( name.isEmpty() || price.isEmpty() ) {
                    JOptionPane.showMessageDialog( null, "상품명 가격입력을 확인바람" );
                } // if
                else {
                    JButton newBtn = new JButton( name + " : " + price );
                    newBtn.addActionListener( new ActionListener() {
                        public void actionPerformed( ActionEvent e ) {
                            int pricei = Integer.parseInt( price );
                            cartModel.addElement( name + " : " + price + "원" );
                            total += pricei;
                            totalLabel.setText( total + "원" );
                        } // actionPerformed()
                    }); // addActionListener()
                } // else
            } // ActionPerformed
        }); // addActionListener
        
        btnAll.add( inputPanel, BorderLayout.NORTH );
        add( btnPanel, BorderLayout.SOUTH );
        setVisible( true );
    } // Pos()
} // Class Pos
