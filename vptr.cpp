#include <iostream>

class A {
public:
    virtual void vfun1() {}
    void fun1() {}
    void fun2() {}

    // int data1;
};

class B : public A {
public:
    void vfun1() override {}
    virtual void vfun2() {}
    void fun1() {}
    void fun2() {}

    // int data2;
};

class C : public B {
public:
    void vfun1() override {}
    void vfun2() override {}
    void fun1() {}
    void fun2() {}

    // int data3;
    // int data4;
};

class S {
    void fun1() {}
};

class T {
public:
    virtual void vfun() = 0;
};

int main() {
    std::cout << "Size of class A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of class B: " << sizeof(B) << " bytes" << std::endl;
    std::cout << "Size of class C: " << sizeof(C) << " bytes" << std::endl;
    std::cout << "Size of empty class S: " << sizeof(S) << " bytes" << std::endl;
    std::cout << "Size of abstract class T: " << sizeof(T) << " bytes" << std::endl;

    std::cout << "Size of pointer: " << sizeof(void*) << " bytes" << std::endl;


    A* base = new C();
    A* base2 = new B();
    A* base3 = new A();
    // std::cout<< (base->_vptr.A)<<std::endl;
    return 0;
}

// Size of class A: 8 bytes
// Size of class B: 8 bytes
// Size of class C: 8 bytes
// Size of empty class S: 1 bytes
// Size of abstract class T: 8 bytes