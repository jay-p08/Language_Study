package objectTest;

public class ToStringTest {
    private String str;
    private int total;

    public ToStringTest() {}
    public ToStringTest(String str, int total) {
        this.str = str;
        this.total = total;
    }

    public String getType() {
        return str;
    }
    public void setType(String str) {
        this.str = str;
    }

    public int getTotal() {
        return total;
    }
    public void setTotal(int total) {
        this.total = total;
    }
    public String toString() {
        return str + ", " + total;
    }

    public static void main(String[] args) {
        ToStringTest test = new ToStringTest("야구", 5);
        System.out.println(test.toString());
    }
}
