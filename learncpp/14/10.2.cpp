#include <iostream>

// class SomeClass {
//     // constant: must be initialised and cannot be changed
//     const std::string m_some_string;
//     SomeClass(std::string some_string);
// };

// /*
//     Issue: in the constructor body we are performing ASSIGNMENT and not
//     INITIALISATION; we can't perform assignment on a const, so it should break
// */

// SomeClass::SomeClass(std::string some_string) {
//     m_some_string = some_string;        // Won't compile
// }   

// int main() {
//     SomeClass my_object("Some string");
// }

class Ball{
    std::string m_colour{};
    double m_radius{};

    public:
        Ball(std::string colour, double radius)
            : m_colour{colour}
            , m_radius{radius}
        {}

        const std::string& get_colour() const {return m_colour;}
        double get_radius() const {return m_radius;}
};

void print_info(const Ball& ball) {
    std::cout   << "Colour: " << ball.get_colour() << "; "
                << "Radius: " << ball.get_radius() << "\n";
}

int main() {
    Ball my_ball("Red", 0.412);
    print_info(my_ball);
}