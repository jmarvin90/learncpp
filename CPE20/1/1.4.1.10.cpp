#include <iostream>

int main() {

    // 34, where * is higher priority than +
    int a {5 * 6 + 4}; 

    // 1, where * and % are equal priority, but have left-side binding
    int b {2 * 3 % 5}; 

    // 12, as the inverse of the above; left-most (%) operator goes first
    int c {6 % 5 * 12};

    int i, j, k, l;
    i = 100;
    j = 25;
    k = 13;
    l = (5 * ((j % k) + i) / (2 * k)) / 2;


    std::cout   << a << "\n"        // 34
                << b << "\n"        // 1
                << c << "\n"        // 12
                << l << "\n";       // 10 - I think because of float truncation

    return 0;
}