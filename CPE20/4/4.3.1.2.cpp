#include <iostream>

void string_concatenation() {
    std::string initial_string {"You're a "};
    std::string subsequent_string {"plonker"};
    std::cout << initial_string + subsequent_string << "\n";
    // Relatively obvious what happens here
}

void cant_concatenate_literals() {
    std::string initial_string {"Who's a "};
    std::string subsequent_string {"plonker?"};

    // Literal and variable is OK
    std::cout << "Who's a " + subsequent_string << "\n";

    // Variable and literal is OK
    std::cout << initial_string + "plonker?" << "\n";

    // Literal and literal is not
    // std::cout << "You're a " + "plonker" << "\n";
}

void string_equality() {
    std::string my_string {"You're a plonker"};
    std::string your_string {"You're a plonker"};
    if (my_string==your_string) {
        std::cout << "We're both plonkers" << "\n";
    }
}

void string_gt_lt() {
    // Alphabetical order; earlier in the alphabet is 'smaller'
    std::string my_string {"A passing thought"};
    std::string your_string {"A moment's notice"};
    std::string_view first_alphabetically{
        (my_string < your_string ? my_string:your_string)
    };

    std::cout << first_alphabetically << "\n";      // A moment's notice
}

void string_method_compare() {
    std::string my_string{"You're a plonker"};
    std::string your_string{"You're a plonker"};
    
    // string compare method comparison
    if (!my_string.compare(your_string)) {
        std::cout << "We're a pair of plonkers" << "\n";
    } else {
        std::cout << "One of us is a real plonker!" << "\n";
    }
}

void string_method_compare_switch() {
    std::string my_string{"Hello there, sir"};
    std::string your_string{"Good day, madam"};
    switch (my_string.compare(your_string)) {
        case 1: std::cout << "Your string is bigger" << "\n"; break;
        case 0: std::cout << "Our strings are the same" << "\n"; break;
        case -1: std::cout << "My string is bigger" << "\n"; break;
    }
}

void string_substring_method() {
    std::string my_string {"You're a plonker, Barry"};
    /*
        substr args: 
            - starting index
            - substring length
    */
    std::cout << my_string.substr(9, 7) << "\n";
    std::cout << my_string.substr(18) << "\n";
}

void string_size_method() {
    std::string my_string{"I'm the plonker now"};
    std::cout << my_string.size() << "\n";
}

void string_compare_substrings() {
    std::string my_string {"You are a plonker, undeniably"};
    std::string your_string {"A plonker? Me?!"};
    std::cout << my_string.compare(10, 7, your_string, 2, 7) << "\n";

    /*
        compare in this guise:
         - substring start
         - substring length
         - comparison string
         - comparison string substring start
         - comparison string substring length
    */
}

void string_find() {
    std::string my_string {"You silly plonker!"};
    std::cout << my_string.find("plonker") << "\n";
}

void not_string_find() {
    std::string my_string {"Something uniquely interesting"};

    /*
        Special type string::npos is returned if the specified substring
        does not exist in the searched string
    */
    if (my_string.find("plonker") == std::string::npos) {
        std::cout << "Doesn't contain plonker!" << "\n";
    }
}

void length_capacity_size() {
    std::string my_string {"Last time I'll say plonker"};
    std::cout   << my_string << "\n" 
                // Max capacity in current buffer
                << "Capacity: " << my_string.capacity() << "\n" 

                // Length in current buffer
                << "Length: " << my_string.length() << "\n"

                // Maximum possible buffer size
                << "Max size: " << my_string.max_size() << "\n";
}

void resize_empty_clear() {
    std::string my_string {"First time I'll say plunker"};
    std::cout << my_string.length() << "/" << my_string.capacity() << "\n";

    /*
        Resize can be used to truncate or extend; when extending, an optional
        'padding' char can be specified
    */
    my_string.resize(40, '\n');
    std::cout << my_string.length() << "/" << my_string.capacity() << "\n";
    std::cout << my_string << "\n";

    my_string.clear();
    std::cout << my_string.empty() << "\n";     // should be truthy (1)
}

void string_index() {
    std::string my_string {"Did sombody say index?"};
    std::cout << my_string[20] << "\n";
}

int main() {
    string_concatenation();
    cant_concatenate_literals();
    string_equality();
    string_gt_lt();
    string_method_compare();
    string_method_compare_switch();
    string_substring_method();
    string_size_method();
    string_compare_substrings();
    string_find();
    not_string_find();
    length_capacity_size();
    resize_empty_clear();
    string_index();
}