public class Exam8 {
    public static void main(String[] args) {
        int[] arr = new int[]{ 1, 2, 3 };

        Saram[] saram = new Saram[3];

        saram[0] = new Saram("πŸ∫∏", 18);
        saram[1] = new Saram("∏Ù∂Û", 18);
        saram[2] = new Saram("∏€√ª¿Ã", 18);

        for (Saram x : saram) {
            System.out.printf("%s, %d\n", x.name, x.age);
        }
    }
}

class Saram {
    public String name;
    public int age;

    public Saram() {} // Saram
    public Saram(String name, int age) {
        this.name = name;
        this.age = age;
    } // Saram
}