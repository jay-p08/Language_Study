package collectionTest1;

import java.util.ArrayList;

public class Store {
    public static ArrayList<Car> cars = new ArrayList<Car>();

    public void add(Car car) {
        cars.add(car);
    }
    public String Brand(String name) {
        for (Car car : cars) {
            if (car.getName().equals(name)) {
                return car.getBrand();
            }
        }
        return String.format("찾을 수 없습니다.");
    }
    public void Check(String brand) {
        for (Car car : cars) {
            if (brand.equals(car.getBrand())) {
                System.out.println(car);
            }
        }
    }
    public void Price(String name, double price) {
        for (Car car : cars) {
            if (car.getName().equals(name)) {
                car.setPrice((int)(car.getPrice() * price));
                break;
            }
        }
    }
}
