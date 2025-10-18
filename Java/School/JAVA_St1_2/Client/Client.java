//package Client;
//
//public class Client {
//    private String name;
//    private int c_money;
//    private int purchase;
//    String tempItem;
//
//    public Client() {
//    }
//
//    public Client(String name, int c_money) {
//        this.name = name;
//        this.c_money = c_money;
//    }
//
//    public void purchase(Item item, int quantity) {
//        int temp = item.getPrice() * quantity;
//        tempItem = item.getName();
//        if (this.c_money > temp) {
//            this.c_money -= temp;
//            item.sales(quantity);
//        }
//        else {
//            System.out.println("돈이 부족합니다.");
//            temp = 0;
//            purchase += temp;
//        }
//
//    }
//
//    public void prt() {
//        System.out.printf("****************\n이름 : %s\n구매품목 : %s\n사이버머니잔액 : %d\n****************\n", name, tempItem, c_money);
//    }
//
//}
