#include <iostream>

class SomeClass {
    std::string m_some_string{};
    std::string m_some_other_string{};
    int m_some_number{};

    public:
        SomeClass(
            std::string_view some_string, 
            std::string_view some_other_string,
            int some_number
        )
        : m_some_string{some_string}
        , m_some_other_string{some_other_string}
        , m_some_number{some_number} {};


        /*
            It's not necessary to explicitly specify a copy constructor to 
            perform copy construction. 

            The default copy constructor is functionally equivalent to the below
            (except the cout statement).
        */

        SomeClass(const SomeClass& some_class)
        : m_some_string{some_class.m_some_string}
        , m_some_other_string{some_class.m_some_other_string}
        , m_some_number{some_class.m_some_number}
        {
            std::cout << "Copy constructing object" << "\n";
        };

        void show() const;
};

void SomeClass::show() const {
    std::cout   << m_some_string << ", "
                << m_some_other_string << ", "
                << m_some_number << "\n";
}

// ------

class SomeClassWontCopy {
    int m_some_number{};

    public:
        SomeClassWontCopy(int some_number): m_some_number{some_number} {};
        
        /* Prevent a new object being created by copy construction */
        SomeClassWontCopy(const SomeClassWontCopy& object) = delete;
};

int main() {
    SomeClass some_class{"James", "Jimbo", 13};
    SomeClass some_other_class{some_class};             // Copy construction

    some_other_class.show();
    
    SomeClassWontCopy temperamental_object(15);

    /*
        The below won't compile because we're trying to invoke a copy 
        constructor that we explicitly deleted
    */
    // SomeClassWontCopy invalid_Copy(temperamental_object);
}

