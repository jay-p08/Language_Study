package markerinterface;

public class Lab {
    public void checkKinds(Animal[] animals) {
        for (int i = 0; i < animals.length; i++) {
            if(animals[i] instanceof HerbivoreMarker) {
                System.out.println("초식 동물입니다.");
            } else if (animals[i] instanceof CarnivoreMarker) {
                System.out.println("육식 동물입니다.");
            } else {
                System.out.println("잡식 동물입니다.");
            }
        }
    }
    public static void main(String[] args) {
        Lab lab = new Lab();

        Animal[] animals = {
                new Bear(),
                new Cow(),
                new Dog(),
                new Tiger()
        };

        lab.checkKinds(animals);
    }
}