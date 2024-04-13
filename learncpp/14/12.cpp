#include <iostream>

class MyClass {
    std::string m_name{};
    int m_num{};

    public: 
        // How we should construct the object with all args
        MyClass(std::string name, int num): m_name{name}, m_num{num} {};

        // How we should delegate onject construction with partial args
        MyClass(std::string name): MyClass{name, 69} {};

        /*
            Note that when delegating object construction it is assumed that the
            constructor being delegated to will do all the work - meaning a 
            constructor that uses delegation cannot attempt to do any member
            initialisation itself.

            You can delegate, or initialise - you can't do both.
            
            For example, you couldn't do:
            
            MyClass(std::string name): MyClass{name, 69}, other_member{69} {}
        */

        void show() const;
};

void MyClass::show() const {
    std::cout << m_name << ", " << m_num << "\n";
}

//----

class AnotherClass {
    std::string m_name{};
    int m_num{};
    
    public:
        // Constructor can make some args optional with default vals 
        AnotherClass(std::string name, int num = 0): m_name{name}, m_num{num} {}
        void show() const;
};

void AnotherClass::show() const {
    std::cout << m_name << ", " << m_num << "\n";
}

//-----

class FinalClass {
    std::string m_name{};
    int m_num{6969};

    public:
        /* 
            For this example, the m_num member will always be initialised as 
            6,969 because there's no constructor that allows for the user to set
            the value
        */
        FinalClass(std::string name): m_name{name} {};
        void show() const;
};

void FinalClass::show() const {
    std::cout << m_name << ", " << m_num << "\n";
}

int main() {
    MyClass my_class{"James"};                  // Should have num val of 69
    MyClass your_class{"Jimbo", 1'000};         // num val 1,000

    AnotherClass another_class{"James"};        // Should have num of 0
    AnotherClass other_class{"Jimbo", 9'999};   // Should have num of 9,999

    FinalClass final_class{"Jarvin"};           // Should have val 6,969    

    my_class.show();
    your_class.show();

    another_class.show();
    other_class.show();

    final_class.show();


}