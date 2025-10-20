#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

class Point;
class Line;

class Point
{
    int x, y;

    public :

        Point() { ; }
        Point( int x, int y )
        {
            this -> x = x;
            this -> y = y;
        }

        int GetX() {
            return this -> x;
        }
        int GetY() {
            return this -> y;
        }
};

class Line
{
    Point p1, p2;

    public :
        Line( Point p1, Point p2 )
        {
            this -> p1 = p1;
            this -> p2 = p2;
        }

        double length()
        {
            return sqrt( pow( ( p2.GetX() - p1.GetX() ), 2 ) + pow( ( p2.GetY() - p1.GetY() ), 2 ) );
        }
};

int main() 
{
    srand( time( NULL ) );

    Point p1( rand() & 10 + 1, rand() & 10 + 1 );
    Point p2( rand() & 10 + 1, rand() & 10 + 1 );

    Line l1( p1, p2 );

    cout << "( " << p1.GetX() << ", " << p1.GetY() << " )" << endl;
    cout << "( " << p2.GetX() << ", " << p2.GetY() << " )" << endl;
    cout << endl << l1.length() << endl;

    return 0;
}