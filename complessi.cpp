#include <iostream>
#include "complessi.hpp"

int main(){
    using com = numero_complesso<double>;
    com c1(1.0,1.0);
    com c2(2.0,2.0);
    double c3 = 12.0;

    std::cout << c1 << " * " << c2 << " = " << c1*c2 << std::endl;
    return 0;
}