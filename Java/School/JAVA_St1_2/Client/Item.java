//package Client;
//
//import java.sql.SQLOutput;
//
//public class Item {
//    private String name;
//    private int price;
//    private int quantity; //남은 수량
//    public int totalSales; // 전체 매출
//    private int salesVolume; // 판매량
//
//    public Item(String name, int price, int quantity) {
//        this.name = name;
//        this.price = price;
//        this.quantity = quantity;
//    }
//
//    public void prt() {
//        System.out.printf("\n****************\n이름 : %s\n가격 : %d\n수량 : %d\n매출액 : %d\n****************\n\n", getName(), getPrice(), getQuantity(), totalSales);
//    }
//
//    public void sales(int salesVolume) {
//        if (salesVolume <= quantity ) {
//            quantity -= salesVolume;
//            totalSales = salesVolume * price;
//        } else {
//            totalSales = 0;
//            quantity += salesVolume;
//            System.out.println("남은 수량의 값이 구매하려는 양 보다 적습니다");
//        }
//    }
//
//    public String getName() {
//        return this.name;
//    }
//    public int getPrice() {
//        return price;
//    }
//    public int getQuantity() {
//        return quantity;
//    }
//
//    public void setName(String name) {
//        this.name = name;
//    }
//    public void setPrice(int price) {
//        this.price = price;
//    }
//    public void setQuantity(int quantity) {
//        this.quantity = quantity;
//    }
//}