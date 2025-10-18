package synchronizedTest;

public class CU {
    public static void main(String[] args) {
        ATM atm = new ATM();

        Thread mom = new Thread(atm, "엄마");
        Thread daughter = new Thread(atm, "딸");

        mom.start();
        daughter.start();
    }
}
