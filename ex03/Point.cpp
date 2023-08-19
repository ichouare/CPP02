#include "./Point.hpp"


Point::Point():x_f(0),y_f(0)
{

}

Point::Point(float x, float y):x_f(x),y_f(y)
{
 
}

Point::~Point()
{

}

Point::Point(const Point &originale)
{
    *(this) = originale;
}

Point& Point::operator=(const Point &obj)
{
    x_f = obj.x_f;
    y_f = obj.y_f;
    return (*this);
}


float Point::get_x() const
{
    return x_f.toFloat();
}

float Point::get_y() const
{
    return y_f.toFloat();
}

float triangle_area( Point const a, Point const b, Point const c)
{
    float area = (1 / 2.0) * (((a.get_x() - b.get_x()) * (a.get_y() - c.get_y())) - ((a.get_x() - c.get_x()) * (a.get_y() - b.get_y())));
    if(area < 0)
        area *= -1;
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float globalS = triangle_area(a, b, c);  // sufrace ABC
    float S1 = triangle_area(point, a, b);  // sufrace PAB
    float S2 = triangle_area(point, b, c);  // sufrace PBC
    float S3 = triangle_area(point, a, c);  // sufrace PAC
    if((S1 + S2 + S3) == globalS)
        return true;
    else
        return  false;
    
}