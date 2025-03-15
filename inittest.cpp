#include <iostream>
#include <vector>

int alla;
double allb;
double *allptr;



class typeA{
public:
    typeA()=default;
    int a;
    double b;
    double *ptr;
};

    

void fun(){
    int a;
    double b;
    std::cout<<"fun "<<a <<" "<<b<<std::endl;
}


int main(){

    std::cout<<"all "<<alla <<" "<<allb<<" "<<allptr<<std::endl;

        int a={};
    double b={};
    std::cout<<"main "<<a <<" "<<b<<std::endl;


    fun();

    typeA obj_a;
    std::cout<<"class A:"<<obj_a.a <<" "<< obj_a.b<<" "<< obj_a.ptr<<std::endl;
}
