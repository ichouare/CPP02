#ifndef POINT_H
#define POINT_H

#include "./Fixed.hpp"
class Point
{
    public:
        Point();
        Point(float x, float y);
        ~Point();
        Point (const Point &originale);
        float get_x() const;
        float get_y() const;
        Point& operator=(const Point &obj);
    private:
        Fixed x_f;
        Fixed y_f;
};


bool bsp( Point const a, Point const b, Point const c, Point const point);
float triangle_area( Point const a, Point const b, Point const c);
std::ostream &operator<<( std::ostream &flux, Fixed const& num);  

#endif

