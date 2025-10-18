import java.awt.Toolkit;
public class BeepTask implements Runnable {
    @Override
    public void run() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        for(int i=0; i<5; i++) {
            toolkit.beep(); // 비프음 발생
            try{ Thread.sleep(500); } catch(Exception e) {}
        }
    }
}

import java.awt.Toolkit;
public class BeepPrintEx2 {
    public static void main(String[] args) {
        Runnable beepTask = new BeepTask();
        Thread thread = new Thread(beepTask);
        thread.start();
        for (int i = 0; i < 5; i++) {
            System.out.println("띵");
            try { Thread.sleep(500); }
            catch (Exception e) {}
        }
    }
}