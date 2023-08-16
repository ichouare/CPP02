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
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;
    private:
        int m_stVal;
        const static int m_fractionBit;
    
};

std::ostream &operator<<( std::ostream &flux, Fixed const& num);  

#endif