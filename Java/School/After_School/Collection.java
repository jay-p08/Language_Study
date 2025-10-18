public class Collection {
    public static void main(String[] args) {
        Sample s1 = new Sample<String>( "안녕하세요" );
        Sample s2 = new Sample<Integer>( 100 );

        System.out.println(s1.getObj());
        System.out.println(s2.getObj());
    }
}

class Sample<T> {
    private T obj;

    public Sample( T obj ) {
        this.obj = obj;
    }

    T getObj() {
        return obj;
    }

    void printInfo() {
        System.out.println( obj.getClass().getName() );
    }
}