package threadTest;

public class ThreadTest1 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread("*");
        MyThread t2 = new MyThread("#");

//        t1.run();
//        t2.run();

        t1.start();
        t2.start();

        System.out.println(Thread.currentThread().getPriority());
        System.out.println(t1.getPriority());
        System.out.println(t2.getPriority());
    }
}
