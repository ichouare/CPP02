#include "Fixed.hpp"

const int Fixed::m_fractionBit = 8;
Fixed::Fixed():m_stVal(0)
{
    //  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{

    // std::cout << "Int constructor called" << std::endl;
    m_stVal = val  << m_fractionBit; // this operation shifting left this is equivalent to multipple by 2^8 or 256 is means to change presentation of val by shiftting  to the left by 8 positions 5 (00000101) => 0000010100000000 ()
    // std::cout << "|" << m_stVal << "|" <<  std::endl;
    setRawBits(m_stVal);
}

Fixed::Fixed(const float val) 
{
  setRawBits(roundf(val * 256));
}   

Fixed::~Fixed()
{
    //   std::cout << "Desconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed &originale)
{
    // std::cout << "Copy constructor called" << std::endl;
    m_stVal = originale.m_stVal;
}


Fixed& Fixed::operator=(const Fixed &obj) 
{
    //  std::cout << "Copy assignment operator called" << std::endl;
     m_stVal = obj.m_stVal;
     return (*this);
}

Fixed Fixed::operator+(const Fixed &obj)
{
    Fixed result;
    result.m_stVal = m_stVal + obj.m_stVal;
    return (result);
}

Fixed Fixed::operator-(const Fixed &obj)
{
    Fixed result;
    result.m_stVal = m_stVal - obj.m_stVal;
    return (result);
}

Fixed Fixed::operator*(const Fixed &obj)
{
    Fixed result;

    result.m_stVal = m_stVal *  obj.m_stVal;
    result.m_stVal = roundf(result.m_stVal / 256.0f);
    return (result);
}

Fixed Fixed::operator/(const Fixed &obj)
{
    Fixed result;
    result.m_stVal = m_stVal / obj.m_stVal;
    return (result);
}


bool  Fixed::operator>(const Fixed &obj)
{
    if(m_stVal >  obj.m_stVal)
        return (true);
    else
        return (false);
}
bool  Fixed::operator>=(const Fixed &obj)
{
    if(m_stVal >=  obj.m_stVal)
        return (true);
    else
        return (false);
}

bool  Fixed::operator<(const Fixed &obj)
{
    if(m_stVal <  obj.m_stVal)
        return (true);
    else
        return (false);
}
bool  Fixed::operator<=(const Fixed &obj)
{
    if(m_stVal <=  obj.m_stVal)
        return (true);
    else
        return (false);
}

bool  Fixed::operator==(const Fixed &obj)
{
    if(m_stVal ==  obj.m_stVal)
        return (true);
    else
        return (false);
}

bool  Fixed::operator!=(const Fixed &obj)
{
    if(m_stVal !=  obj.m_stVal)
        return (true);
    else
        return (false);
}

Fixed Fixed::operator++()
{
    m_stVal += 1;
    return *this;
}


Fixed   Fixed::operator++(int)
{
    Fixed  b = Fixed(*this); 
    m_stVal += 1;
    return b;
}

Fixed   Fixed::operator--()
{

    m_stVal = m_stVal + 1;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed  b = Fixed(*this); 
    m_stVal -= 1;
    return b;
}

int Fixed::getRawBits( void ) const
{
    return m_stVal;
}
 

void Fixed::setRawBits( int const raw )
{
    m_stVal = raw;
}


int Fixed::toInt(void) const
{
    return m_stVal / 256.0f;
}

float Fixed::toFloat( void ) const
{
    return (float)(m_stVal / 256.0f);
}

Fixed const & Fixed::min(Fixed  const  &obj1, Fixed const & obj2)
{
    if(obj1.m_stVal < obj2.m_stVal)
        return obj1;
    else
        return obj2;
}

Fixed const & Fixed::max(Fixed  const  &obj1 , Fixed const &obj2)
{
    if(obj1.m_stVal >  obj2.m_stVal)
        return obj1;
    else
        return obj2;
}

Fixed const & Fixed::min(Fixed  &obj1, Fixed  &obj2)
{
    if(obj1.m_stVal < obj2.m_stVal)
        return obj1;
    else
        return obj2;
}

Fixed const & Fixed::max(Fixed    & obj1, Fixed  &  obj2)
{
    if(obj1.m_stVal > obj2.m_stVal)
        return obj1;
    else
        return obj2;
}



std::ostream &operator<<( std::ostream &flux, Fixed const& num)
{

   flux << (num.getRawBits() / 256.0f);
    return flux;
}

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
    return x_f.toFloat() / 256.0f;
}

float Point::get_y() const
{
    return y_f.toFloat() / 256.0f;
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
