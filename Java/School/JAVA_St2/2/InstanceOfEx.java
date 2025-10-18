// instanceof �삁�젣: 媛앹껜�쓽 ����엯�쓣 �솗�씤�븯�뒗 諛⑸쾿
public class InstanceOfEx {
    
    // print() 硫붿꽌�뱶�뒗 Person ����엯�쓽 媛앹껜瑜� 諛쏆븘 �빐�떦 媛앹껜媛� �뼱�뼡 ����엯�씤吏� 異쒕젰
    static void print( Person p ) {
        if( p instanceof Person ) // p媛� Person�쓽 �씤�뒪�꽩�뒪�씤吏� �솗�씤
            System.out.print( "Person" );
        if( p instanceof Student ) // p媛� Student�쓽 �씤�뒪�꽩�뒪�씤吏� �솗�씤
            System.out.print( "Student" );
        if( p instanceof Researcher ) // p媛� Researcher�쓽 �씤�뒪�꽩�뒪�씤吏� �솗�씤
            System.out.print( "Researcher" );
        if( p instanceof Professor ) // p媛� Professor�쓽 �씤�뒪�꽩�뒪�씤吏� �솗�씤
            System.out.print( "Professor" );
        System.out.println(); // 媛� 異쒕젰 �썑 以� 諛붽퓞
    }

    public static void main( String[] args ) {
        // 媛� 媛앹껜�쓽 ����엯�쓣 print() 硫붿꽌�뱶濡� 異쒕젰
        System.out.println( "new Student() -> \t" ); print( new Student() );
        System.out.println( "new Researcher() -> \t" ); print( new Researcher() );
        System.out.println( "new Professor() -> \t" ); print( new Professor() );
    }
}

// Person �겢�옒�뒪 (�뒋�띁 �겢�옒�뒪)
class Person { }

// Student �겢�옒�뒪 (Person�쓣 �긽�냽諛쏆쓬)
class Student extends Person { }

// Researcher �겢�옒�뒪 (Person�쓣 �긽�냽諛쏆쓬)
class Researcher extends Person { }

// Professor �겢�옒�뒪 (Person�쓣 �긽�냽諛쏆쓬)
class Professor extends Person { }
