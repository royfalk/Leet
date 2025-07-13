#ifndef OOP_H
#define OOP_H

class Base {
public:
    virtual void foo();
    void bar();
};

class Derived : public Base {
public:
    void foo() override;
    void bar();
};

void testOOP();

#endif // OOP_H