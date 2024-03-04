#include <iostream>

int main() {
    int i{1};

    int j;
    j = i++;        // assign i's value to j; increment i by 1

    std::cout << j << "  " << i << "\n";    // 1  2



    int k{1};

    int l;
    l = ++k;        // increment k's value; assign k's value to l
    
    std::cout << l << "  " << k << "\n";    // 2  2


    int a, b;
    a = 4;
    b = 2 * a++;    // Copy assign, then increment a by 1
    a = 2 * --b;    // Decrement b by 1; copy assign result
    
    std::cout << a << "  " << b << "\n";   // 14   7 
}