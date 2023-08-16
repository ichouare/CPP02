#ifndef FIXED_H
#define FIXED_H



#include <iostream>
#include <string>


class Fixed 
{
    public:
    Fixed();
    ~Fixed();
    Fixed (const Fixed &originale);
    void operator=(Fixed &obj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    private:
        int m_stVal;
        const static int m_fractionBit;  
};


#endif