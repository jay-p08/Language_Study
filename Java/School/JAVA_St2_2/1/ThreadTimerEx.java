import java.awt.*;
import javax.swing.*;
class TimerThread extends Thread {
    private JLabel timerLabel;
    public TimerThread(JLabel timerLabel) {
        this.timerLabel = timerLabel;
    }
    @Override
    public void run() {
        int n=0;
        while(true) {
            timerLabel.setText(Integer.toString(n));
            n++;
            try {
                Thread.sleep(1000);
            }
            catch(InterruptedException e) {
                return;
            }
        }
    }
}

public class ThreadTimerEx extends JFrame {
    public ThreadTimerEx() {
        setTitle(“Thread를 상속받은 타이머 스레드 예제”);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JLabel timerLabel = new JLabel();
        timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
        c.add(timerLabel);
        TimerThread th = new TimerThread(timerLabel);
        setSize(300,170);
        setVisible(true);
        th.start();
    }
    public static void main(String[] args) {
        new ThreadTimerEx();
        for(int i=0; i<100; i++) {
            System.out.println("Main 스레드" + i);
        }
    }
}