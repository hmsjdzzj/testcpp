# inittest.cpp

测试默认初始化

all		 全局变量：默认初始化为0.

main	使用{}进行初始化：初始化为0.

fun	   函数内的局部变量：未定义

class	类的成员变量的默认初始化：未定义

![image-20250316145629385](readme.assets/image-20250316145629385.png)





# move.cpp

测试移动拷贝构造函数  的默认行为

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

// std::unique_ptr<MyClass> ptr2 = ptr1; // This line would cause a compile error

![image-20250316150427510](readme.assets/image-20250316150427510.png)



# reference.cpp

测试引用的参数传递

补充：返回的时候因为编译器默认了返回值优化，所以不会调用拷贝构造或移动拷贝构造。



此外还测试了 new 抛出的异常，会结束程序；但try catch 可以保持程序继续运行。

![image-20250316150733903](readme.assets/image-20250316150733903.png)





# bool.cpp

vector<bool>会有一些问题

这里用vector<char>进行代替，验证了输出时可以完成char到bool的转换；

![image-20250316191209251](readme.assets/image-20250316191209251.png)





# namespace.cpp

测试了命名空间；可以多次定义补充定义。

![image-20250316191429509](readme.assets/image-20250316191429509.png)





# test_move.cpp

测试了返回值优化；

测试了如果不使用移动拷贝，会转化为拷贝构造。



![image-20250316192043389](readme.assets/image-20250316192043389.png)



# type_trans.cpp

测试了类型转换过程中的warning。

默认是不会warning的，比如int转size_t、double转int；

这里会warning，是因为类型转换时使用了{},会强制执行类型检查。

![image-20250316192541371](readme.assets/image-20250316192541371.png)





# vptr.cpp

测试了虚函数的大小

S是空类，占用1字节；

其他类都是有继承关系的有虚函数的A B C； 大小是一个虚指针的大小，所以是8字节；

T是纯虚函数，也是8B；

![image-20250316192754265](readme.assets/image-20250316192754265.png)