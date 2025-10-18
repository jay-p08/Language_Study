package collectionTest1;

import java.util.ArrayList;

public class Main2 {
    public static void main(String[] args) {
        Store store = new Store();

        Car c1 = new Car("현대", "소나타", 2500);
        Car c2 = new Car("기아", "스포티지", 2800);
        Car c3 = new Car("기아", "쏘렌토", 3800);
        Car c4 = new Car("벤츠", "차3", 4000);
        Car c5 = new Car("삼성", "sm3", 2000);

        store.add(c1);
        store.add(c2);
        store.add(c3);
        store.add(c4);
        store.add(c5);

        store.Check("기아");
        System.out.println(store.Brand("sm3"));

        store.Price("차3", 1.2);
        System.out.println(c4);
    }
}
