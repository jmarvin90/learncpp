#include <iostream>
#include <string>

class GenericEvent {
};

template <typename T>
class SpecificEvent: public GenericEvent {

    public:
        void show() {
            std::cout << T().the_string << "\n";
        }
};

int main() {
    SpecificEvent<GoodEvent> my_event;
    my_event.show();

    SpecificEvent<BadEvent> your_event;
    your_event.show();
}