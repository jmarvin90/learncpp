#include <iostream>


// Creating a struct where all fields are zero initialised
struct Person{
    std::string name {};
    unsigned int age {};
    std::string favourite_colour{};
    std::string Person{};               // It's fine for these names to overlap
    // Person favourite_person {}       <- this would be invalid!
};                                      // The struct definition terminates with ;

int main() {
    Person person {"James Marvin", 33, "orange", "Alex Hazell"};
    std::cout   << person.name << " " 
                << person.age << " " 
                << person.favourite_colour << " " 
                << person.Person << " "
                << sizeof(person) << " bytes \n";
    return 0;
}