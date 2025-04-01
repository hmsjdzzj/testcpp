#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
using namespace std;

class BC {
public:
    virtual void xm()=0;
    virtual void load()=0;
    virtual ~BC() = default; // Virtual destructor for proper cleanup
};


class FIX : public BC {
public:
    void xm() override {
        std::cout << "FIX::xm called" << std::endl;
        cout<<"value is "<<fixvalue<<endl;
    }
    void load()  {
        cin>>fixvalue;
    }
    int fixvalue = 42; // Example value for fixvalue
};

class WALL : public BC {
public:
    void xm() override {
        std::cout << "WALL::xm called" << std::endl;
        cout<<"twall is "<<twall<<endl;
    }
    void load() { // Changed to REAL (double)
        cin>>twall;
    }
    double twall = 0.0; // Example value for twall as REAL (double)
};


class BCFactoryBase {
public:
    using Ptr = BCFactoryBase*;
    virtual BC* create() =0;
};

template <class Derived>
class BCFactory : public BCFactoryBase {
public:
    BC* create() override {
        return new Derived();
    }
};

// BCFactoryBase::Ptr createBC(int type) {
//     switch (type) {
//         case 1: {
//             return std::make_shared<BCFactory<FIX>>();
//         }
//         case 2: {
//             return std::make_shared<BCFactory<WALL>>();
//         }
//         default:
//             std::cout << "Invalid type" << std::endl;
//             return nullptr;
//     }
// }



// struct Peoson { 
//     virtual void show()=0;
//     virtual ~Peoson() {};
// };

// struct Student : public Peoson {
//     void show() override {
//         cout<<"I am a student"<<endl;
//     }
// };

// struct Teacher : public Peoson {
//     void show() override {
//         cout<<"I am a teacher"<<endl;
//     }
// };
    
// template <class B>
// struct Fatory {
//     static Peoson* create(int i) {
//         return new B();
//     } 
// };





int main() {
    
    // vector< BC * > bcs;
    // bcs.push_back(new FIX());
    // bcs.push_back(new WALL());

    // // Call virtual function xm
    // for(auto &bc : bcs) {
    //     bc->xm();
    // }
    std::map<int, BCFactoryBase* > bc_map = {
        {1, new BCFactory<FIX>()},
        {2, new BCFactory<WALL>()}
    };
     



    int type=0;
    cin>>type;
    auto bc = bc_map[type]->create();
    // BC * bc = nullptr;
    // // std::map<int, BCFactoryBase::Ptr> bc_map;
    // switch (type) {
    //     case 1: {
    //         bc = new FIX();
    //         // bc->load(100); // Example usage
    //         break;
    //     }
    //     case 2: {
    //         bc = new WALL();
    //         // bc->load(200.5); // Example usage
    //         break;
    //     }
    //     default:
    //         std::cout << "Invalid type" << std::endl;
    //         break;
    // }
    bc->load();
    bc->xm();









    // auto p = Fatory<Student>::create(1);
    // p->show();




    return 0;
}