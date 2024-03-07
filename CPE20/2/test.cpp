#include <iostream>

void mod_div_truthy_falsey() {
    /*
        Answering this question depended on the ability to determine what t 
        looked like after the for loop.

        That required:
            - Identifying the right spot in the array to populate a value;
            - Getting a truthy/falsey from modulo division of i by 2
            - Inverting the truthy/falsey and assigning the output to the array

        I got this wrong because 0%2 is 0, not 2.

        Remember: modulo division against 0 is always 0.
    */
    bool t[5];
    for (int i=0; i<5; i++) {
        t[4-i] = !(i%2);

        // Let's see what's happening as we go
        std::cout << "i: "      << i << "; "
                  << "i%2: "    << i%2 << "; " 
                  << "!(i%2): " << !(i%2) << "\n";
    }

    // Let's see the final outcome
    for (int i=0; i<5; i++) {
        std::cout << t[i] << "\n";
    }
}

void do_while() {
    /*
        Answering this question depended on understanding the number of 
        times the while loop body would be executed.
        
        Because the body of the loop is executed before the while condition is
        evaluated, the body of the loop will run (once) while the condition
        (i>=0) is actually false - so the loop runs one more time than you
        might expect.
    */
    int i{3}, j{0};
    do {
        i--;
        j++;

        // See what's happening as we go
        std::cout   << "i: " << i << "; "
                    << "j: " << j << ";\n";
    } while (i>=0);

    // The answer should be:
    std::cout << "Answer: " << j << "\n";
}

void neg_array_val() {
    /*
        Answering this question depended knowing how many times the for loop
        body would be executed.
        
        To do that, you need to spot that:
            1. The loop condition is evaluated based on the contents of an array
            2. The contents of the array are changed during the loop body
            3. The first loop ensures that the loop condition is met after
               one execution

        i is incremented to 2, which NOT smaller than -2. The loop body executes
        once.
    */
    int t[] {8, 4, 3, 2, 1}, i;
    for (i=t[4]; i<t[0]; i++) {
        std::cout   << "i: " << i << "; "
                    << "t[i-1]: " << t[i-1] << "; "
                    << "-t[3]: "  << -t[3] << ";\n";
        t[i-1] = -t[3];
    }
}

int main() {
    mod_div_truthy_falsey();
    do_while();
    neg_array_val();
    return 0;
}