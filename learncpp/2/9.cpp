#include <iostream>
#include <string>

/* Defining a namespace */
namespace my_namespace {
    void say_something(std::string something);
}

/* Creating a function definition outside of the namespace block by using a qualifier*/
void my_namespace::say_something(std::string something) {
    std::cout << something << "\n";
}


namespace your_namespace {
    // std::cout << "Something!"; <- would error - no raw executable statements in a namespace block

    /* Executable statements can be included within function definitions, however */
    void say_something(std::string something) {
        std::cout << something << "\n";
    }
}

int main() {
    /* Functions with identical names can be defined using namespaces to disambiguate */
    my_namespace::say_something("This is my namespace...");
    your_namespace::say_something("...And this is your namespace!");
    return 0;
}

