package javacos;

public class Exam1 {
    public static void main(String[] args) {
        FarmMachine fm1 = new FarmMachine(2025, 1000000, "red");

        System.out.println(fm1.getYear());
        System.out.println( String.format( "%,d", fm1.getPrice() ) );
        System.out.println(fm1.getColor());

        fm1.move();
        fm1.digging();
        fm1.grinding();
    }
}

class FarmMachine {
    private int year;
    private int price;
    private String color;

    public FarmMachine(int year, int price, String color) {
        this.year = year;
        this.price = price;
        this.color = color;
    }

    public int getYear() {
        return year;
    } // getYear()

    public int getPrice() {
        return price;
    } // getPrice()

    public String getColor() {
        return color;
    } // getColor()

    public void move() {
        System.out.println("Fram-machine is moving.");
    } // move()

    public void digging() {
        System.out.println("Fram-machine is digging.");
    } // digging()

    public void grinding() {
        System.out.println("Fram-machine is grinding.");
    } // grinding()
}