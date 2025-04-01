#include <iostream>
using namespace std;

class A {
public:
    // Pure virtual function
    virtual void pureVirtualFunction() = 0;

    // Virtual function
    virtual void virtualFunction() {
        std::cout << "A::virtualFunction" << std::endl;
    }

    // Non-virtual function
    void nonVirtualFunction() {
        std::cout << "A::nonVirtualFunction" << std::endl;
    }

    virtual ~A() = default; // Virtual destructor
};

//##########################################################################
//必须在类外实现纯虚函数
void A::pureVirtualFunction() {
    cout<<"类外实现纯虚函数"<<endl;
    std::cout << "A::pureVirtualFunction" << std::endl;
}
//##########################################################################

class B : public A {
public:
    // Override pure virtual function              这个函数必须给继承、否则编译报错
    void pureVirtualFunction() override {
        std::cout << "B::pureVirtualFunction" << std::endl;
        A::pureVirtualFunction();
    }

    // Override virtual function
    // void virtualFunction() override {
    //     std::cout << "B::virtualFunction" << std::endl;
    // }

    // Non-virtual function (hides A's non-virtual function)
    void nonVirtualFunction() {
        std::cout << "B::nonVirtualFunction" << std::endl;
    }
};

int main() {
    A* obj = new B();
    cout<<endl;

    //1 Call pure virtual function   只继承接口
    cout<<"1、B类调用纯虚函数"<<endl;
    cout<<"执行自己的(B类必须实现纯虚函数,否则编译报错)"<<endl;
    obj->pureVirtualFunction();
    cout<<endl;

    //2 Call virtual function     继承接口和缺省实现
    cout<<"2、B类调用非纯虚函数"<<endl;
    cout<<"实现了则调用自己的,缺省则调用基类的"<<endl;
    obj->virtualFunction();
    cout<<endl;

    //3 Call non-virtual function     继承接口和强制实现
    cout<<"3、B类调用非虚函数"<<endl;
    cout<<"实现不实现都是调用基类的"<<endl;
    obj->nonVirtualFunction();
    cout<<endl;

    delete obj;

    B* obj2 = new B();
    cout<<"当这个指针指向B 才实现B类的"<<endl;
    obj2->nonVirtualFunction();
    cout<<endl;

    return 0;
}