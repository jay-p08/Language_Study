package javacos;

public class Exan7 {
    public static void main(String[] args) {
        Goblin z = new Goblin( "좀비", "1111", 1, 9.9 );
        z.print();
    }
}

class Monster {
    private String name;

    public Monster() {} // Monster
    public Monster(String name) {
        this.name = name;
    } // Monster

    public String getName() {
        return name;
    } // getName

    public void setName(String name) {
        this.name = name;
    } // setName
} // class Monster

class Goblin extends Monster {
    private String key;
    private int weapon;
    private double power;

    public Goblin() {} // Goblin
    public Goblin(String name, String key, int weapon, double power) {
        super(name);
        this.weapon = weapon;
        this.key = key;
        this.power = power;
    } // Goblin

    public int getWeapon() {
        return weapon;
    } // getPower

    public void setWeapon(int power) {
        this.weapon = power;
    } // setPower

    public double getPower() {
        return power;
    } // getPower
    public void setPower(double power) {
        this.power = power;
    } // setPower
    public String getKey() {
        return key;
    } // getKey
    public void setKey(String key) {
        this.key = key;
    } // setKey

    public void print() {
        System.out.printf("이름 : %s, 키 : %s, 무기 : %d, 힘 : %.1f\n", getName(), key, weapon, power);
    }
} // class Goblin