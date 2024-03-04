#include <iostream>

/* 
Edube example includes a using namespace instruction
Have left out as potentially bad practice.
*/

/* 
Edube example has a void arg; have skipped this.

From learncpp.com: 

    Although this will compile in C++ (for backwards compatibility reasons), 
    this use of keyword void is considered deprecated in C++. The following 
    (exclude void) code is equivalent, and preferred in C++
*/

int main() { 
    /*
    Edube example didn't have the newline char. Subsequent examples
    may prefer endl
    */
   
    std::cout << "It's me, your first program!" << "\n";

    /* Zero indicates success; 1 indicates failure */
    return 0;
}