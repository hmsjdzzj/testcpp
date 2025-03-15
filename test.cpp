#include <iostream>
#include <vector>
class Complex {
public:
    int real, imag;
    Complex() =default;//{printf("hello\n");}
    Complex(int r, int i) : real(r), imag(i) {printf("created! %d \n",real);}
    Complex(const Complex & other) :real(other.real) {printf("copy created %d !\n",real);}    //是的，拷贝构造函数必须&，只能用引用，不然传参的时候是拷贝，然后还没有定义拷贝；

    // 重载加法运算符
     Complex  operator + (const Complex &other) const{
        return Complex(other.real,other.imag);
    }
    ~Complex(){
        printf("%d+%di\n",real,imag);
    }
    //  Complex  operator + (const Complex &other) const{
    //     return other;
    // }
    //  Complex  operator + (const Complex &other) const{
    //     Complex a(other.real,other.imag);
    //     return a;
    // }
//！！！！！！！！！！！！！！！！！！！！！
//这两种return都要拷贝一次；
//区别是
//第一种进行了正常的构造函数；
//第二种等价于return Complex(other) 调用拷贝构造； 
//第三种还是只调用了一次构造函数; 可能是编译器优化了？和第一种一致。
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

    

void fun(){
std::vector<Complex*> obj;
    Complex *test1 = new Complex(10,10);
    obj.push_back(test1);
    delete test1;
}


int main(){
    Complex a(1,1);
    const  Complex b(2,2);
    
    // func(a,b,&c);
    // c.display();
    //c = a+b;
    fun();
Complex c(4,4);
try{
    Complex * ptr = new Complex[99999999999999];
}catch(std::bad_alloc &ba){
    std::cerr << "hello " <<ba.what() <<std::endl;
}

}
