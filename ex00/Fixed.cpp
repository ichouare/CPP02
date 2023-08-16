#include "Fixed.hpp"

const int Fixed::m_fractionBit = 8;
Fixed::Fixed():m_stVal(0)
{
     std::cout << "Default constructor called" << std::endl;
}



Fixed::~Fixed()
{
      std::cout << "Desconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed &originale)
{
    std::cout << "Copy constructor called" << std::endl;
    m_stVal = originale.getRawBits();
}


void Fixed::operator=(Fixed &obj)
{
     std::cout << "Copy assignment operator called" << std::endl;
     m_stVal = obj.getRawBits();
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return m_stVal;
}


void Fixed::setRawBits( int const raw )
{
    m_stVal = raw;
}