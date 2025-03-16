# inittest.cpp

测试默认初始化

all		 全局变量：默认初始化为0.

main	使用{}进行初始化：初始化为0.

fun	   函数内的局部变量：未定义

class	类的成员变量的默认初始化：未定义

![image-20250316145629385](readme.assets/image-20250316145629385.png)





# move.cpp

测试移动拷贝构造函数

// test1:  不写，因为定义了拷贝构造，移动语义会变成拷贝构造。

// test2: 声明为delete   调用move时会编译出错。

​	// MyClass(MyClass&& other) =delete;   

// test3: 声明为default

​	// MyClass(MyClass&& other) =default;   

// test4: 自己声明

  //   data = other.data;

  //   *data+=100;

  //   other.data = nullptr;

  //   std::cout << "Move Constructor called, value: " << *data << std::endl;

  // }

![image-20250316145926240](readme.assets/image-20250316145926240.png)



# smart_ptr.cpp

测试unique指针的拷贝（移动）

![image-20250316150427510](readme.assets/image-20250316150427510.png)



# reference.cpp

测试引用的参数传递

补充：返回的时候因为编译器默认了返回值优化，所以不会调用拷贝构造或移动拷贝构造。



此外还测试了 new 抛出的异常，会结束程序；但try catch 可以保持程序继续运行。

![image-20250316150733903](readme.assets/image-20250316150733903.png)

