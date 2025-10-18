public class EqualsEx2 {
    public static void main(String[] args) {
        
    }
}

class Rect {
    private int width, height;

    public Rect( int width, int height ) {
        this.width = width; this.height = height;
    }

    public boolean equals( Object obj ) {
        Rect p = ( Rect )obj;
        if( width*height == p.width*p.height ) return true;
        else return false;
    }
}