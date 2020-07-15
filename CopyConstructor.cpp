/*
 * =====================================================================================
 *
 *       Filename:  CopyConstructor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/14/2020 09:50:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Point
{
    public:

        Point(int a = 0, int b = 0):x(a),y(b)
        {

        }

        // Copy constructor
        Point(Point & p)
        {
            x = p.x;
            y = p.y;
        }

        friend ostream & operator<<(ostream & ofs, const Point &p)
        {
            return ofs << "(" << p.x << "," << p.y << ")";
        }
    
    private:
        int x;
        int y;
};

int main(int argc, char **argv)
{
    Point p(10,47);

    cout << "Original point object : " << p << endl;

    Point q(p);

    cout << "Copied point object(copy constructor) : " << q << endl;

    return 0;
}
