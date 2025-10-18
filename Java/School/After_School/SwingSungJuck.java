import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SwingSungJuck {
    private static Grademanager manager = new Grademanager();
    private static JPanel topJPanel;
    private static JPanel centerJPanel;
    private static JTextArea outputArea;

    public SwingSungJuck() {
        JFrame jframe = new JFrame();
        topJPanel = new JPanel( new FlowLayout() );

        jframe.setLayout( new BorderLayout() );
        jframe.add( topJPanel, BorderLayout.NORTH );
        jframe.setSize( 500, 300 );
        jframe.setLocationRelativeTo(null );
        jframe.setVisible( true );

        centerJPanel = new JPanel();
        centerJPanel.setLayout( new FlowLayout() 
        );

    } // SwingSungJuck()

    public static void main( String[] args ) {
        JFrame frame = new JFrame( "학생 성적 관리 시스템" );
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.setSize( 700, 500 );

        JButton addButton = new JButton( "등록" );
        JButton viewButton = new JButton( "조회" );
        JButton gradeButton = new JButton( "성적입력" );
        JButton printButton = new JButton( "성적표출력" );
        JButton exitButton = new JButton( "종료" );

        addButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                showAddForm();
            }
        }); // addButton

        viewButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                showViewForm();
            }
        }); // viewButton

        gradeButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                showGradeForm();
            }
        }); // gradeButton

        printButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                printGradeSheet();
            }
        }); // printButton

        exitButton.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                System.exit( 0 );
            }
        }); // exitButton

        topJPanel.add(addButton);
        topJPanel.add(viewButton);
        topJPanel.add(gradeButton);
        topJPanel.add(printButton);
        topJPanel.add(exitButton);

        centerJPanel = new JPanel();
        centerJPanel.setLayout( new FlowLayout( FlowLayout.LEFT, 10, 10) );

        outputArea = new JTextArea( 10, 60 );
        outputArea.setEditable( false );
        JScrollPane scrollPane = new JScrollPane( outputArea );

        frame.setLayout( new BorderLayout() );
        frame.add( topJPanel, BorderLayout.NORTH );
        frame.add( centerJPanel, BorderLayout.CENTER );
        frame.add( scrollPane, BorderLayout.SOUTH );
        frame.setVisible( true );

    }// main

    private static void showAddForm() {
        centerJPanel.removeAll();

        JTextField idField = new JTextField();
        idField.setPreferredSize( new Dimension( 150, 25 ) );
        JTextField nameField = new JTextField();
        nameField.setPreferredSize( new Dimension( 150, 25 ) );
        JButton submit = new JButton( "등록" );

        submit.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                String id = idField.getText();
                String name = nameField.getText();
                outputArea.setText( "" );
                if( !id.isEmpty() && !name.isEmpty() ) {
                    Student s = new Student( id, name );
                    manager.addStudent( s );
                    outputArea.append( "학생 등록 완료 >>> " + id + " - " + name + "\n" );
                } // if
                else {
                    outputArea.append( "학번과 이름을 모두 입력하세요.\n" );
                }
            } // actionPerformed()

        }); // submit.addActionListener()

        centerJPanel.add( new JLabel( "학번 >>> ") );
        centerJPanel.add( idField );
        centerJPanel.add( new JLabel( "이름 >>> ") );
        centerJPanel.add( nameField );
        centerJPanel.add( submit );

        centerJPanel.revalidate();
        centerJPanel.repaint();
    } // showAddForm()

    private static void showViewForm() {
        centerJPanel.removeAll();

        JTextField idField = new JTextField();
        idField.setPreferredSize(new Dimension( 150, 25));
        JButton search = new JButton( "조회" );

        search.addActionListener(new ActionListener() {
            public void actionPerformed( ActionEvent e ) {

            }
        });
    } // showViewForm()

    private static void showGradeForm() {
        centerJPanel.removeAll();
        JTextField idField = new JTextField();
        idField.setPreferredSize( new Dimension( 150, 25 ) );
        JTextField subField = new JTextField();
        subField.setPreferredSize( new Dimension( 150, 25 ) );
        JTextField ScoreField = new JTextField();
        ScoreField.setPreferredSize( new Dimension( 150, 25 ) );
        JButton save = new JButton( "입력" );

        save.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String id = idField.getText();
                    Student s = manager.findStudent(id);
                    if( s == null ) {
                        outputArea.append( "X 학생 없음 : " + id + "\n" );
                        return;
                    } // if
                    String sub = subField.getText();
                    int score = Integer.parseInt(ScoreField.getText());
                    Subject subject = new Subject(sub, score);
                    s.addOrUpdateSubject(subject);
                    outputArea.append( "성적 입력 : " + s.getName() + "-" + sub + "\n" );
                } // try
                catch( Exception ex ) {
                    outputArea.append( "X 입력 오류 : 숫자를 정확히 입력했는지 확인하세요.\n" );
                } // catch
            }
        });
        centerJPanel.add(new JLabel( "학번 : " ));
        centerJPanel.add(idField);
        centerJPanel.add(new JLabel( "과목 : " ));
        centerJPanel.add(subField);
        centerJPanel.add(new JLabel( "성적 : " ));
        centerJPanel.add(ScoreField);
        centerJPanel.add(save);
        centerJPanel.revalidate();
        centerJPanel.repaint();
    } // showGradeForm()

    private static void printGradeSheet() {
        outputArea.append( "성적표 출력 : \n" );
        if (manager.getStudents().isEmpty()) {
            outputArea.append( "X 학생 없음" );
            return;
        }
        for( Student s : manager.getStudents() ) {
            outputArea.append( "- " + s.getName() + " (" + s.getStudentId() + ")\n");
            if( s.getSubjects().isEmpty()) {
                outputArea.append(" 과목 없음\n");
            } // if
            else {
                for( Subject sub : s.getSubjects() ) {
                    outputArea.append( " * " + sub.getName() + " | 성적 : " + sub.getScore() + "\n");
                } // for
                double avg = s.calculateAverage();
                outputArea.append(" 평균 성적 : " + avg + "\n");
            } // else
        } // for
        outputArea.append("\n");
    } // printGradeSheet()
    
} // SwingSunJuck

class Student {
    private String studentId;
    private String name;
    private ArrayList<Subject> subjects = new ArrayList<>();

    public Student( String studentId, String name ) {
        this.studentId = studentId;
        this.name = name;
    } // Student

    public String getStudentId() {
        return studentId;
    } // getStudentId()
    public String getName() {
        return name;
    } // getName
    public ArrayList<Subject> getSubjects() {
        return subjects;
    } // getSubjects()

    public void addOrUpdateSubject( Subject s ) {
        for( Subject sub : subjects ) {
            if( sub.getName().equals( s.getName() ) ) {
                sub.setScore( s.getScore() );
                return;
            } // if
        } // for
        subjects.add( s );
    } // addOrUpdateSubject()

    public double calculateAverage() {
        if( subjects.isEmpty() ) {
            return 0.0;
        } // if

        int totalScore = 0;

        for( Subject s : subjects ) {
            totalScore += s.getScore();
        } // for

        return (double)totalScore / subjects.size();
    } // caculateAverage()

    public String toString() {
        return "학번 >>> " + studentId + ", 이름 >>> " + name;
    } // toString()
} // Student

class Subject {
    private String name;
    private int score;

    public Subject( String name, int score ) {
        this.name = name;
        this.score = score;
    } // Subject

    public String getName() {
        return name;
    } // getName()
    public int getScore() {
        return score;
    } // getScore
    public void setScore( int score ) {
        this.score = score;
    } // setScore

} // Subject

class Grademanager {
    private ArrayList<Student> students = new ArrayList<>();
    
    public void addStudent( Student s ) {
        students.add( s );
    } // addStudent()
    public Student findStudent( String id ) {
        for( Student s : students ) {
            if( s.getStudentId().equals( id ) ) {
                return s;
            } // if
        } // for
        return null;
    } // findStudent()
    public ArrayList<Student> getStudents() {
        return students;
    } // getStudents()
} // Grademanager