import java.util.ArrayList;
import java.util.Scanner;

public class BankTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        Bank bank = new Bank();

        // Bank
        while ( true ) {
            System.out.println( "\n================================================은행업문================================================" );
            System.out.println( "[1] 계좌생성\t[2] 계좌조회\t[3] 입금\t[4] 출금\t[5] 모든계좌보기\t[6] 이름 검색\t[7] 계좌 삭제\t[8] 정렬\t[9] 프로그램 종료\n" );
            System.out.print("메뉴를 골라주세요 >>> " );
            int choice = sc.nextInt();

            sc.nextLine();
            // Menu
            if( choice == 1 ) { // 계좌 생성
                System.out.print( "계좌번호 입력 >>> " );
                String Account_Number = sc.nextLine();

                System.out.print( "계좌 소유자 이름 >>> " );
                String Account_Name = sc.nextLine();

                System.out.print( "초기 입금액 >>> " );
                int Balance = sc.nextInt();

                sc.nextLine();

                Account account = new Account( Account_Number, Account_Name, Balance );
                bank.addAccount( account );

                System.out.println( "새 계좌 생성완료" );
            } // 계좌 생성
            else if ( choice == 2 ) { // 계좌 조회
                System.out.print( "계좌번호 입력 >>> " );
                String Account_Number = sc.nextLine();
                Account account = bank.findAccount( Account_Number );

                System.out.println( account );
            } // 계좌 조회
            else if ( choice == 3 ) { // 입금
                System.out.print( "계좌번호 입력 >>> " );
                String Account_Number = sc.nextLine();
                Account account = bank.findAccount( Account_Number );

                if ( account != null ) { // if
                    System.out.print( "입금할 금액 >>> ");
                    int money = sc.nextInt();
                    account.deposit( money );
                    System.out.println( "입금 완료" );
                } // if
                else System.out.println( "해당 계좌번호가 없습니다." );
            } // 입금
            else if ( choice == 4 ) { // 출금
                System.out.print( "계좌번호 입력 >>> " );
                String Account_Number = sc.nextLine();
                Account account = bank.findAccount( Account_Number );

                if ( account != null ) { // if
                    System.out.print( "출금할 금액 >>> ");
                    int money = sc.nextInt();
                    account.widthow( money );
                } // if
                else System.out.println( "해당 계좌번호가 없습니다." );
            } // 출금
            else if ( choice == 5 ) { // 모든계좌보기
                bank.listAccounts();
            } // 모든계좌보기
            else if () {

            } // 이름 검색
            else if ( choice == 9 ) break; // 프로그램 종료
            else System.out.println( "잘못된 메뉴" );
        } // while

        sc.close();
    } // main

} // Class BankTest

class Account {
    private String Account_Number;
    private String Account_Name;
    private int Balance;

    public Account() {;}
    public Account( String Account_Number, String Account_Name, int Balance ) {
        this.Account_Number = Account_Number;
        this.Account_Name = Account_Name;
        this.Balance = Balance;
    } // Account

    public String getAccountNumber() {
        return Account_Number;
    } // getAccountNumber
    public String getAccountName() {
        return Account_Name;
    } // getAccountName
    public int getBalance() {
        return Balance;
    } // getBalance
    public void setAccountNumber( String Account_Number ) {
        this.Account_Number = Account_Number;
    } // setAccountNumber
    public void setAccountName( String Account_Name ) {
        this.Account_Name = Account_Name;
    } // setAccountName
    public void setBalance( int Balance ) {
        this.Balance = Balance;
    } // setBalance

    public void deposit( int Balance ) {
        this.Balance += Balance;
        System.out.println( "입금완료" );
    } // deposit
    public void widthow( int Balance ) {
        if( this.Balance >= Balance ) {
            this.Balance -= Balance;
            System.out.println( "정상 출금 완료" );
        } else System.out.println( "잔액부족" );
    } // widthow

    public String toString() {
        return "AccountNumber = " + Account_Number + ", AccountName = " + Account_Name + ", Balance = " + Balance;
    } // toString
} // class Acount

class Bank {
    private ArrayList<Account> accounts;
    public Bank() {
        accounts = new ArrayList<>();
    }
    public Bank( ArrayList<Account> account ) {
        accounts = account;
    } // Bank

    public void addAccount( Account account ) {
        accounts.add( account );
    } // addAccount
    public Account findAccount( String accountNumber ) {
        for( Account account : accounts ) 
            if( account.getAccountNumber().equals(accountNumber) ) 
                return account;
        return null;
    } // findAccount
    public void listAccounts() {
        if( accounts.isEmpty() )
            System.out.println();
        accounts.forEach( System.out::println );
    } // listAccounts
} // class Bank