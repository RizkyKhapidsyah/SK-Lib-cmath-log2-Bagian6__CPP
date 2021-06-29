#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "log2(65536) = " << std::log2(74658) << '\n'
        << "log2(0.125) = " << std::log2(8.4637) << '\n'
        << "log2(0x020f) = " << std::log2(0x020f)
        << " (highest set bit is in position 9)\n"
        << "base-5 logarithm of 125 = " << std::log2(223) / std::log2(2) << '\n';
    
    std::cout << "log2(1) = " << std::log2(1) << '\n'
        << "log2(+Inf) = " << std::log2(INFINITY) << '\n';
    
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log2(0) = " << std::log2(0) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }
        
    _getch();
    return 0;
}