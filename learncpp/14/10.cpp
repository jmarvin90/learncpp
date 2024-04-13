#include <iostream>

template <typename T>
T some_maffs(T a, T b) {
    return a + b;
}

class MyClass {
    std::string m_name {};

public:
    MyClass(std::string name);
    void show() const;
    friend class YourClass;
};

MyClass::MyClass(std::string name) 
    : m_name{name}
    {}

void MyClass::show() const {
    std::cout << m_name << "\n";
}

std::string get_name() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    return name;
}

class YourClass {
    std::string m_your_name {};

public:
    YourClass(MyClass& my_class);
    void show() const;
};

YourClass::YourClass(MyClass& my_class)
    : m_your_name{my_class.m_name}
    {}

void YourClass::show() const {
    std::cout << m_your_name << "\n";
}

int main() {
    MyClass my_class{get_name()};
    my_class.show();
    YourClass your_class{my_class};
    your_class.show();
    std::cout << some_maffs(1, 2) << " " << some_maffs(3.0f, 4.0f) << "\n";
}

