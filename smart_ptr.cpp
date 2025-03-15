#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : value(value) {
        std::cout << "MyClass constructor: " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor: " << value << std::endl;
    }
    int getValue() const {
        return value;
    }
private:
    int value;
};

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(10);

    // Transferring ownership from ptr1 to ptr2
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    if (ptr1) {
        std::cout << "ptr1 is not null" << std::endl;
    } else {
        std::cout << "ptr1 is null" << std::endl;
    }

    if (ptr2) {
        std::cout << "ptr2 is not null and points to: " << ptr2->getValue() << std::endl;
    } else {
        std::cout << "ptr2 is null" << std::endl;
    }

    return 0;
}