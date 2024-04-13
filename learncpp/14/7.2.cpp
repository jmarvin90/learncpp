#include <iostream>

class SomeAggregate {
    public:
        std::string first_one{};
        std::string second_one{};
};

class SomeClass {
    private:
        std::string m_name{};
    public:
        void set_name(std::string name);
        const std::string& get_name() const;
};

void SomeClass::set_name(std::string name) {
    m_name = name;
}

const std::string& SomeClass::get_name() const {
    return m_name;
}

int main() {
    SomeClass my_object = SomeClass();
    my_object.set_name("Mames Jarvin");

    std::cout << my_object.get_name() << "\n";


    /* 
        For aggregates, members are initialised in the order in which they 
        are defined.

        Aggregates can't/shouldn't have private members or constructors, so list 
        initialisation won't work for classes with private attrs.
    */

    SomeAggregate my_aggregate{"Something", "Something else"};
    std::cout   << my_aggregate.first_one << ", " 
                << my_aggregate.second_one << "\n";

    return 0;
}