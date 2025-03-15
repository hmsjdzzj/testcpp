#include <iostream>
#include <utility>

class Nomove{
    public:
    Nomove() = default;
    Nomove(const Nomove&) = default;
    Nomove& operator=(const Nomove&) = default;
    ~Nomove() = default;
    Nomove(Nomove&&) = delete;


private:
    int data;
};

class MyClass {
public:
    int* data;
    // Nomove nomove;
    // Constructor
    MyClass(int value) {
        data = new int(value);
        std::cout << "Constructor called, value: " << *data << std::endl;
    }
    
    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        *data+=9;
        std::cout << "Copy Constructor called, value: " << *data << std::endl;
    }

    // #####################################################################
    // Move Constructor

    // test1:  不写，因为定义了拷贝构造，移动语义会变成拷贝构造。

    // test2: 声明为delete     调用move时会编译出错。
    // MyClass(MyClass&& other) =delete;    

    // test3: 声明为default
    // MyClass(MyClass&& other) =default;    

    // test4: 自己声明
    // MyClass(MyClass&& other) noexcept {
    //     data = other.data;
    //     *data+=100;
    //     other.data = nullptr;
    //     std::cout << "Move Constructor called, value: " << *data << std::endl;
    // }
    
    // Destructor
    ~MyClass() {
        if (data) {
            std::cout << "Destructor called, value: " << *data << std::endl;
            delete data;
        } else {
            std::cout << "Destructor called, data is nullptr" << std::endl;
        }
    }
};

int main() {
    MyClass obj1(10);           // Constructor
    MyClass obj2(obj1);        // Copy Constructor
    MyClass obj3(std::move(obj1) ); // Move Constructor
    
    return 0;
}