#include "oop.h"

#include <iostream>

void Base::foo() {
    std::cout << "Base foo" << std::endl;
}

void Base::bar() {
    std::cout << "Base bar" << std::endl;
}

void Derived::foo() {
    std::cout << "Derived foo" << std::endl;
}

void Derived::bar() {
    std::cout << "Derived bar" << std::endl;
}

void testOOP() {
    Base base;
    Derived derived;
    
    // This is pretty obvious
    Base* ptr = &base;
    ptr->foo(); // Calls Derived::foo
    ptr->bar(); // Calls Derived::bar
    ptr = &derived;
    ptr->foo(); // Calls Derived::foo
    ptr->bar(); // Calls Derived::bar

    // But can this even compile?
    Base cast = derived; // This is slicing
    cast.foo(); // Calls Base::foo, not Derived::foo
    cast.bar(); // Calls Base::bar, not Derived::bar
}