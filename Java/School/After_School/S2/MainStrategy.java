public class MainStrategy {
    public static void main(String[] args) {
        SumPrinter sumprinter = new sumprinter();
        sumprinter.print( new GaussSum(), 10 )
        sumprinter.print( new SimpleSum(), 10 )
    }
}
