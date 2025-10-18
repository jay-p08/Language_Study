public class Main2 {
    public static void main(String[] args) {
        Car[] car = new Car[3];

        car[0] = new Car(1500, 4000, "벤츠");
        car[1] = new Car( 2000, 3000, "그랜져" );
        car[2] = new Car( 1000, 1500, "아반테" );

        for( int i = 0 ; i < 3 ; i++ ) {
            car[i].print();
        }
    }
}

class Vehide {
    public String modeName;
    public  int price;

    public Vehide( String modeName, int price ) {
        this.modeName = modeName; this.price = price;
    }
}

class Car extends Vehide {
    int displacement;
    float duty = 0;

    public Car( int displacement, int price, String modeName ) {
        super(modeName, price); this.displacement = displacement;
    }

    public float Duty() {
        if ( displacement >= 3000) {
            duty = ( price * 5 )/100;
        } else if ( displacement < 3000 && displacement >= 1500 ) {
            duty = ( price * 3 )/100;
        } else if ( displacement < 1500 ) {
            duty = price/100;
        } else System.out.println( "Error" );

        return duty;
    }

    public void print() {
        System.out.printf("모델명 = %s, 가격 = %d, 배기량 = %d, 세금 = %.1f\n", this.modeName, this.price, this.displacement, Duty());
    }
}