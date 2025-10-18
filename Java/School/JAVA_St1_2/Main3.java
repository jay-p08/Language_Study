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
        System.out.println("나는 나는 새이다.");
    }
}

class Fish extends Animal {
    public void move() {
        System.out.println("나는 수영을 하는 물고기이다.");
    }
}

class Bird extends Animal {
    public void move() {
        System.out.println("나는 나는 새이다.");
    }
}

class Dog extends Animal {
    public void move() {
        System.out.println("나는 킁킁 거리며 돌아 다니는 개이다.");
    }
    public void back() {
        System.out.println("나는 멍멍 하고 짓는다.");
    }
}