public class Main3 {
    public static void main(String[] args) {
        Animal[] aniArr = new Animal[3];

        aniArr[0] = new Bird();
        aniArr[1] = new Fish();
        aniArr[2] = new Dog();

        aniArr[0].move();
        aniArr[1].move();
        aniArr[2].move();

        ((Dog) aniArr[2]).back();
    }
}

class Animal {
    public void move() {
        System.out.println("���� ���� ���̴�.");
    }
}

class Fish extends Animal {
    public void move() {
        System.out.println("���� ������ �ϴ� ������̴�.");
    }
}

class Bird extends Animal {
    public void move() {
        System.out.println("���� ���� ���̴�.");
    }
}

class Dog extends Animal {
    public void move() {
        System.out.println("���� ůů �Ÿ��� ���� �ٴϴ� ���̴�.");
    }
    public void back() {
        System.out.println("���� �۸� �ϰ� ���´�.");
    }
}