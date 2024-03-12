#include <iostream>

void show_vector(const std::vector<int>& vec) {
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

std::vector<int> sort(std::vector<int> vec) {
    bool swapped;

    do {
        swapped = false;
        for (int i=0; i<vec.size()-1; i++) {
            if (vec[i] > vec[i+1]) {
                swapped = true;
                std::swap(vec[i], vec[i+1]);
            }
        }
    } while (swapped);

    return vec;
}

int main() {
    std::vector<int> my_vec {10, 7, 5, 3, 2, 1};
    std::vector<int> swapped_vec{sort(my_vec)};
    show_vector(swapped_vec);
    return 0;
}