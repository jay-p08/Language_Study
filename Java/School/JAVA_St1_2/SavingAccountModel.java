//import java.util.Scanner;
//
//public class SavingAccountModel {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        System.out.println("잔고 입력 : ");
//        SavingAccount rPwhk1 = new SavingAccount(10000);
//        SavingAccount rPwhk2 = new SavingAccount(20000);
//
//        SavingAccount.updateInterest(0.05);
//
//        System.out.printf("1번의 계좌번호는 %d입니다.\n", rPwhk1.AccountName());
//        System.out.printf("2번의 계좌번호는 %d입니다.\n", rPwhk2.AccountName());
//
//        rPwhk1.calMonthInterest();
//        rPwhk2.calMonthInterest();
//
//        System.out.printf("%d의 현재 잔고 : %d\n", rPwhk1.AccountName(), rPwhk1.getBalance());
//        System.out.printf("%d의 현재 잔고 : %d\n", rPwhk2.AccountName(), rPwhk2.getBalance());
//
//        SavingAccount.updateInterest(0.06);
//
//        rPwhk1.calMonthInterest();
//        rPwhk2.calMonthInterest();
//
//        System.out.printf("%d의 현재 잔고 : %d\n", rPwhk1.AccountName(), rPwhk1.getBalance());
//        System.out.printf("%d의 현재 잔고 : %d\n", rPwhk2.AccountName(), rPwhk2.getBalance());
//    }
//}
//class SavingAccount{
//    private double Account;
//    private int AccountName;
//    public static double annualInterest;
//
//    public SavingAccount(int Account) {
//        this.Account = Account;
//        AccountName = (int)(Math.random() * 9999 + 1000);
//
//    }
//    void calMonthInterest() {
//        Account += Account*(annualInterest/12);
//    }
//    int getBalance() {
//        return (int)Math.round(Account);
//    }
//    static void updateInterest(double annualInterest) {
//        SavingAccount.annualInterest = annualInterest;
//    }
//    int AccountName() {
//       return AccountName;
//    }
//}