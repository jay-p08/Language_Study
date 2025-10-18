/*
public class ShipMain {
    public static void main(String[] args) {
        ShipMenu s1 = new ShipMenu(10, 10, "박재영 호");

        System.out.println(s1.PrintPassengers());
        System.out.println(s1.PrintLuggage());
    }
}
interface Ship {
    public int Passengers();
    public int Luggage();
}
class ShipMenu implements Ship {
    private int passengers;
    private int luggage;
    private String name;

    public ShipMenu(int passengers, int luggage, String name) {
        this.passengers = passengers;
        this.luggage = luggage;
        this.name = name;
    }

    public int Passengers() {
        return passengers;
    }
    public int Luggage() {
        return luggage;
    }

    public String PrintPassengers() {
        return String.format("최대 탑승 인원 : %d명", Passengers());
    }
    public String PrintLuggage() {
        return String.format("최대 적재량 : %dkg", Luggage());
    }

}*/
