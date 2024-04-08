#include <iostream>

class YourClass{
    int m_var {2};

public:
    // Const to indicate it doesn't alter class state 
    void show_var() const;              
};

class MyClass {
public:
    int m_var {1};
    void show_var();                    // Declaration
    void increment_var();
};                                      // Class defs need a closing ;

/*
    Member functions can be made 'const' by including the const keyword 
    after the function name/parameter list.

    Const member functions guarantee not to modify the state of the object.

    Attempting call a non-const member functions on a const object instance
    will result in a compilation error.
*/
void YourClass::show_var() const {
    std::cout << m_var << "\n";
}

void MyClass::show_var() {              // Definition
    std::cout << m_var << "\n";
}

void MyClass::increment_var() {
    m_var++;
}

const int get_int() {
    return 5;
}

int main() {
    const YourClass your_class {};
    your_class.show_var();              // Should show 2

    MyClass my_class {};                // Initialised
    my_class.increment_var();
    my_class.show_var();                // Should show 2

}