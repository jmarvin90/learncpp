#include <iostream>

int main() {
    std::vector<int>    numbers     {1, 5, 10, 20, 50};

    /*  An array declaration does not need to specify the number of elements - 
        that can be inferred from the initial values                        */
    int                 numbers_[]  {1, 5, 10, 20, 50};

    // Arrays aren't aware of their size
    for (int i=0; i<5; i++) {
        std::cout << numbers_[i];
    }

    std::cout << "\n";

    // std::vectors are
    for (int i=0; i <=numbers.size()-1; i++) {
        std::cout << numbers[i];
    }

    std::cout << "\n";

    return 0;

}