#include <iostream>

class MyClass {
    std::string m_name {"James"};

public:
    std::string set_name(std::string name) {
        m_name = name;
        return name;
    }

    /*
        The first const denotes the specific (const) type of reference being
        returned; this ensures that the value being referenced (m_name) is
        not modifiable through the reference.

        The second const denotes that the member function does not alter the
        class state, ensuring that function can be called on a const instance.
    */
    const std::string& get_name() const {
        return m_name;
    }
};

int main() {
    const MyClass james{};
    MyClass haze{};

    haze.set_name("Haze");
    
    // james.set_name("Marv");              // Not valid on a const object!

    std::cout << haze.get_name() << " " << james.get_name() << "\n";
}