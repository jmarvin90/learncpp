#include <iostream>

int main() {
    int counter;                // Declared but not initialised 
    int counter_2, counter_3;   // Multiple declarations are OK 

    // 'Copy' assignment; value on right side is 'copied' to the variable 
    counter = 1;                

    // Further notes from learncpp.com: 

    /* 
        The process of specifying an initial value for an object is called
        INITIALISATION; the syntax used to initialise an object is called an 
        INITIALISER.
    */

   int a;                   // No initialiser    
   int width = 5;           // Copy initialisation 
   int height(10);          // Direct initialistaion 

   int depth {20};          // Direct list initialisation       - PREFERRED 
   int diameter {};         // Value initialisation             - PREFERRED 
   int volume = {30};       // Copy list initialisation 


}