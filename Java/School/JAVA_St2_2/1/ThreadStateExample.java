class TargetThread extends Thread {
    @Override
    public void run() {
        for (long i = 0; i < 2000000000; i++)
            for (long j = 0; j < 2000000000; j++) {
            }
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
        }
        for (long i = 0; i < 2000000000; i++)
            for (long j = 0; j < 2000000000; j++) {
            }
    }
}

class StatePrintThread extends Thread {
    private Thread targetThread;

    public StatePrintThread(Thread targetThread) {
        this.targetThread = targetThread;
    }

    @Override
    public void run() {
        while (true) {
            Thread.State state = targetThread.getState();
            System.out.println("타겟 스레드 상태 : " + state);
            if (state == Thread.State.NEW)
                targetThread.start();

            if (state == Thread.State.TERMINATED)

                break;

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }
}

public class ThreadStateExample {
    public static void main(String[] args) {
        StatePrintThread statePrintThread =

                new StatePrintThread(new TargetThread());

        statePrintThread.start();
    }
}