#include "Fixed.hpp"

const int Fixed::m_fractionBit = 8;
Fixed::Fixed():m_stVal(0)
{
     std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{

    std::cout << "Int constructor called" << std::endl;
    m_stVal = val  << m_fractionBit; // this operation shifting left this is equivalent to multipple by 2^8 or 256 is means to change presentation of val by shiftting  to the left by 8 positions 5 (00000101) => 0000010100000000 ()
    // std::cout << "|" << m_stVal << "|" <<  std::endl;
    setRawBits(m_stVal);
}

Fixed::Fixed(const float val)
{
    std::cout << "float constructor called" << std::endl;
    setRawBits(roundf(val * 256));
}   

Fixed::~Fixed()
{
      std::cout << "Desconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed &originale)
{
    std::cout << "Copy constructor called" << std::endl;
   *(this) = originale;
}


Fixed& Fixed::operator=(const Fixed &obj)
{
     std::cout << "Copy assignment operator called" << std::endl;
     m_stVal = obj.m_stVal;
      return (*this);
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


std::ostream &operator<<( std::ostream &flux, Fixed const& num)
{

   flux << (num.getRawBits() / 256.0f);
    return flux;
}