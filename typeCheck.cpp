#include <iostream>

// Base class A
class A {
public:
    virtual void display() const {
        std::cout << "This is class A" << std::endl;
    }
    // virtual const std::type_info& type() const { return typeid(A); }
    virtual ~A() = default; // Virtual destructor for proper cleanup
};

// Derived class B
class B : public A {
public:
    // const std::type_info& type() const override { return typeid(B); }   
    void display() const override {
        std::cout << "This is class B" << std::endl;
    }
};

// Derived class C
class C : public A {
public:
    // const std::type_info& type() const override { return typeid(C); }
    void display() const override {
        std::cout << "This is class C" << std::endl;
    }
};

// Function to handle polymorphism for A
// 统一入口函数
void handle(const A* obj) {
    if (typeid(*obj) == typeid(B)) {
        std::cout << "Handling B* (via A*)" << std::endl;
        obj->display();
    } else if (typeid(*obj) == typeid(C)) {
        std::cout << "Handling C* (via A*)" << std::endl;
        obj->display();
    } else {
        std::cout << "Handling A* (base)" << std::endl;
        obj->display();
    }
}

// // Overloaded function to handle B
// void handle(const B* obj) {
//     std::cout << "Handling object of type B" << std::endl;
//     obj->display();
// }

// // Overloaded function to handle C
// void handle(const C* obj) {
//     std::cout << "Handling object of type C" << std::endl;
//     obj->display();
// }

int main() {
    A* b = new B();
    A* c = new C();
    A* a = new A();

    handle(b); // Calls B's specific handle
    handle(c); // Calls C's specific handle
    handle(a);                   // Calls A's handle

    // Clean up
    delete b;
    delete c;
    delete a;

    return 0;
}
