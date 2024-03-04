#include <iostream>

int main() {
    float var;
    var = .1;
    var = var + 1.;
    /**/ var = var + 1e1;
    // var = var + 1e-2

    std::cout << var << "\n";


    int k{}, l{}, m{};
    l = (10 % 3 * 10 / 3);
    m = (3 % 10 - 3 / 10);
    k = l / m;
    std::cout << l << '\\' << m << '=' << k << "\n";
}