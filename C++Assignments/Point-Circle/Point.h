#ifndef POINT_H
#define POINT_H
#include <iostream> //for ostream objects
class Point {

    private:
        int x;//x-coordinate
        int y;//y-coordinate

    public:
        int getX() const { return x; }
        int getY() const { return y; }
        void setX(int v) { x = v; }
        void setY(int v) { y = v; }

        Point(int v1=0, int v2=0) {//serves as default constructor too
            setX(v1);
            setY(v2);
        }

        friend std::ostream& operator<<(std::ostream& out, const Point& p) {
            out << "(" << p.getX()
                << ", " << p.getY()
                << ")";
            return out;
        }//end overloaded stream insertion
        
       	// istream >>
		friend std::istream& operator>>(std::istream& is, Point& p)
			{ // start of the operator overload
				is >> p.x >> p.y;			
				return is;
			} // end of the operator overload
				
};//end class definition
#endif
