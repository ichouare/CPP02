#include "./Fixed.hpp"


int main()
{
   Point a(0, 0);
   Point b(20, 0);
   Point c(10, 30);
   Point p(19, 2.9);
   if (bsp(a, b, c, p))
     std::cout <<"Inside";
   else
     std::cout <<"Not Inside";
}
   return 0;