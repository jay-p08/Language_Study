/*
package Account;

public class SavingAccount extends Account {
    int month;
    double interest;

    public SavingAccount(String a_number, int balance, int month, double interest) {
        super(a_number, balance);
        this.month = month;
        this.interest = interest;
    }

    double GetInterest() {
        return interest;
    }
    void SetInterest(double interest) {
        this.interest = interest;
    }

    @Override
    public void Withdraw(int amount) {
        if(balance >= amount) {
            balance -= amount;
            System.out.printf("현제 잔고 : %d", balance);
        } else {
            System.out.println("잔고가 부족합니다.");
        }
    }

    double Calculate(double interest) {
        return interest/12;
    }

    public String PrintBalance() {
        return String.format("당신의 계좌번호는 %s 입니다. 잔고 : %d, 기간 : %d, 이율 : %.2f\n", a_number, balance, month, interest);
    }
}*/
