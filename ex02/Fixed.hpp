#ifndef FIXED_H
#define FIXED_H



#include <iostream>
#include <string>
#include <math.h>

class Fixed 
{
    public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    ~Fixed();
    Fixed (const Fixed &originale);
    Fixed& operator=(const Fixed &obj);
    bool  operator>(const Fixed &obj);
    bool  operator>=(const Fixed &obj);
    bool  operator<(const Fixed &obj);
    bool  operator<=(const Fixed &obj);
    bool  operator==(const Fixed &obj);
    bool operator!=(const Fixed &obj);
    Fixed  operator+(const Fixed &obj);
    Fixed  operator-(const Fixed &obj);
    Fixed  operator*(const Fixed &obj);
    Fixed  operator/(const Fixed &obj);
    Fixed   operator++();
    Fixed   operator--();
    Fixed  operator++(int);
    Fixed  operator--(int);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;
    static Fixed const & min(Fixed const &  obj1, Fixed const &  obj2);
    static Fixed const & min(Fixed  &  obj1, Fixed  &  obj2);
    static Fixed const & max(Fixed const &  obj1, Fixed const &  obj2);
    static Fixed const & max(Fixed  &  obj1, Fixed  &  obj2);
    private:
        int m_stVal;
        const static int m_fractionBit;
    
};

std::ostream &operator<<( std::ostream &flux, Fixed const& num);  

#endif