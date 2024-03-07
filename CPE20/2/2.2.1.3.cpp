#include <iostream>

int main() {
    double big {1e15};
    double small {1e-15};

    std::cout << std::fixed << big << "\n";         // 1000000000000000.0
    std::cout << std::fixed << small << "\n";       // 0.0000000000000001

    std::cout << std::fixed << big + small;         // 1.0000000000000000.000000
    /* 
        This is because there's a limit to the number of significant digits
        the double can hold; less significant digits are dropped (I guess?) 
    */
}