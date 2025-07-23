#include <iostream>
#include <ctime>

// consteval - specifies that a function is an immediate function, 
// that is, every call to the function must produce a compile-time constant  
consteval int ce_add(int a, int b) {
    return a+b;
}



void const_test() {
    std::cout << "const_test\n";

    constexpr int cx = 1; // Defined at compile time
    const time_t t = time(0);  // Defined at runtime

    //cx++; // fail at compile
    //t++; // fail at compile
    
    const int c = ce_add(1,5);
    constexpr int ce = ce_add(8,5);

    // Fail at compile
    // call to consteval function "ce_add" did not produce a valid constant expression
    // call to consteval function "ce_add" did not produce a valid constant expression
    //const int t1 = ce_add(t, 4);
}