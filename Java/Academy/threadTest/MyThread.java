package threadTest;

public class MyThread extends Thread {
    public String str;
    public MyThread(String str) {
        this.str = str;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(str);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(str + "쓰레드 종료");
    }
}
