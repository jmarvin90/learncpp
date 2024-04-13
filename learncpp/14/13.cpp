#include <iostream>

class TestClass {
    int m_x{};
    int m_y{};

    public:
        TestClass(int x = 0, int y = 0): m_x{x}, m_y{y} {};
        void show() const;
};

void TestClass::show() const {
    std::cout << m_x << ": " << m_y << "\n";
}

void show(TestClass some_class) {
    some_class.show();
}

int main() {
    /*
        The non-member show function accepts an object instance in order to call
        the member show function.

        In this case, instead of an already-initialised object, we're just
        passing an initialiser list.

        Apparently, the compiler should be smart enough to create the temporary
        object we need to call show() using the initialiser list.
    */

    show({12, 14});


    /*
        The following statement should achieve the same outcome as the one
        above.

        In the case they're functionally identicaly, maybe this lower one is
        better (easier to see what's going on?)
    */

   show(TestClass(12, 14));
}