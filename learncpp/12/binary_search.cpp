#include <iostream>

int search(std::vector<int>& vec, int val) {
    int power{1};

    while (power < vec.size()) {
        power <<= 1;
    }

    int index{0};

    while (power) {
        int n_index {index+power};

        if ((n_index < vec.size()) && (vec[n_index] <= val)) {
            index += power;
        }

        /* Not sure about this - perhaps should be outside of the loop*/
        if (vec[index] == val) {
            return index;
        }

        power >>= 1;
    }

    return -1;
}

int main() {
    std::vector my_vector {1, 3, 5, 7, 9};
    std::cout << "Index position: " << search(my_vector, 5) << "\n";
    return 0;
}