#include <iostream>
//奇妙递归模板模式（Curiously Recurring Template Pattern，CRTP）


//子类转基类，可以隐私转换
//基类转子类，需要dynamic_cast


// Base class template using CRTP
template <typename Derived>
class A {
public:
    void displayall() const {
        static_cast<const Derived*>(this)->display();           //这里单纯的是类型转换，类似把int* 转换为double*；所以不用dynamic_cast
    }
};

// Derived class B
class B : public A<B> {
public:
    B(int a):a(a){}
    void display() const {
        std::cout << "This is class B;a=" << a << std::endl;
    }
private:
    int a;
};

// Derived class C
class C : public A<C> {
public:
    void display() const {
        std::cout << "This is class C" << std::endl;
    }
};

// Function to handle objects of type A
template <typename T>
void handle(const A<T>& obj) {          //静态转换为基类
    std::cout << "Handling object of type " << typeid(T).name() << std::endl;
    obj.displayall();
}

void handle(const B & obj){              //B是一个更精确的模板
    std::cout << "Handling B" << std::endl;
    obj.display();
}

int main() {
    B b(2);
    C c;

    handle(b); // Calls B's specific handle
    handle(c); // Calls C's specific handle

    return 0;
}
