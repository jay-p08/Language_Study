import java.awt.Toolkit;
public class BeepThread extends Thread {

    @Override
    public void run() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        for (int i = 0; i < 5; i++) {
            toolkit.beep(); // 비프음 발생
            try {
            Thread.sleep(500);
            } catch (Exception e) {}
        }
    }
}
public class BeepPrintEx {
    public static void main(String[] args) {
        Thread thread = new BeepThread();
        thread.start(); // 스레드 실행
        for(int i=0; i<5; i++) { // 메인스레드
            System.out.print("띵 ");
            try {
                Thread.sleep(500);
            } catch(Exception e) {}
        }
    }
}