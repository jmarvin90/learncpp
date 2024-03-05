#include <iostream>

int main() {
    uint32_t l{10};                     // 1010 bin
    uint32_t r{5};                      // 0101 bin
    uint32_t m{3};                      // 0011 bin

    uint32_t both{l|r};                 // 1111 bin;                                    15
    uint32_t neither{l&r};              // 0000 bin;                                    0  
    uint32_t swap{~l};                  // 1111 1111 1111 1111 1111 1111 1111 0101 bin; 4294967285
    uint32_t exor{l^m};                 // 1001 bin;                                    9

    // Should output 15, 0, 246, 6
    std::cout   << both     << " "
                << neither  << " "
                << swap     << " "
                << exor     << " "
                << "\n";
}