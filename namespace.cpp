#include<iostream>
namespace A {
    void func() {
        // 第一部分定义
        std::cout << "Hello from A::func" << std::endl;
    }
}

// 在同一作用域中再次定义命名空间 A
namespace A {
    void anotherFunc() {
        // 补充定义
        std::cout << "Hello from A::anotherFunc" << std::endl;
    }
}

namespace A::son{
    void anotherFunc() {
        // 补充定义
        std::cout << "Hello from A::son::anotherFunc" << std::endl;
    }
}
// 使用命名空间 A
int main() {
    A::func();          // 调用第一个函数
    A::anotherFunc();   // 调用第二个函数
    A::son::anotherFunc();
    return 0;
}