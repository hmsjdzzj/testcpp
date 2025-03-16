#include <iostream>
#include <cstring>
using namespace std;

class TestObj {
public:
    string name="obj1";
    int * data=nullptr;
    size_t *use=nullptr;     //动态内存的引用计数


    TestObj():data(new int(1)),use(new size_t(1)) { cout << "Constructor." << endl; }
    TestObj(const TestObj& other):name(other.name+"_2"),data(other.data),use(other.use) { ++*use; cout << "Copy Constructor." << endl; }
    TestObj(TestObj&& other)=delete;//:name(other.name+"_2"),data(other.data),use(other.use) { cout << "Move Constructor." << endl; }
    ~TestObj() {     
        if(--*use ==0){
            delete data;
            delete use;
        }
        cout << "Destructor."  <<name  << endl; 
    }
};

TestObj GetRef(int x) {
    TestObj toTemp1;
    TestObj toTemp2;
    if(x>10){
        return toTemp1;
    }
    else return toTemp2;
}

void TakeRef(const TestObj &obj) {
    cout<<obj.name<<endl;
    cout<< *(obj.data)<<endl;
    cout<< *(obj.use)<<endl;
}

int main(int argc, char** argv) {
    TakeRef(GetRef(2));
    return 0;
}


