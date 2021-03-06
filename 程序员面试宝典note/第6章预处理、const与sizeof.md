1. 用宏定义声明一个常数表示一年中有多少秒（忽略闰年）
    + `#define  SECONDS_PER_YEAR  (60*60*24*365)UL`, 其中`UL`防止在16位机器中**溢出**
2. `const`修饰指针的规则
    + 如果`const`位于星号**左侧**(const *)，则修饰指针所指向的变量（常量指针，常量的指针），`const int *p` or `int const *p`，则可以不初始化变量p，p的值可以改，但不能通过*p去修改p指向的那个值。（说白了就是*p整体是个常量）
    + 如果`const`位于星号**右侧**(* const)，则修饰指针本身（指针常量，指针是常量），`int* const p = xxx`，即指针本身是常量，则必须初始化p，p指向的内容可以变，但p不能指向别的变量。（p是个常量，此时p是个指针类型）
3. `const`修饰成员函数：放前 v.s. 放后
    + `const int func1(); // 返回值是个常量`
    + `int func2() const; // 不能修改成员数据，对于只读函数都应该养成这样的编码风格`
4. 类中的`const`成员初始化：通过**初始化列表**
    ```c++
    class A {
      public:
        A(int n, int *ptr): a(n), q(ptr) {}; 
        // 这样初始化是不通过语法的 A(int n, int *ptr) {a = n; q = ptr};
      private:
        const int a; // must init
        const int *p;
        int* const q; // must init
    }
5. `const`与`#define`的对比
    + `const`常量有数据类型，编译器可以进行类型安全检查；`#define`只是字符替换
    + 一般来说可以对`const`常量进行调试，但不能对宏常量调试。c++中一般只使用`const`常量而不使用宏常量
6. 一个参数既可以是const也可以是volatile。典型的例子是只读的状态寄存器。
7. `sizeof`
    + 应考虑字节对齐（编译时确定的）
    + 只计算栈中分配的大小，如在类中定义一个`static`变量，则不会算上该变量的大小
    + 是个操作符，不是个函数
        + `sizeof(type)` // 如果是类型，则必须有括号
        + `sizeof var` // 如果是变量则可以不加括号，也可以加
8. `int **a[3][4]`在32位机器上`sizeof(a)`是多少？
    + `[]`优先级高于`*`，因此答案是`3 * 4 * sizeof(int**) = 48`
9.  `sizeof(class)`:
    + 成员函数不占空间，成员变量才占空间
    + 如果class为**空类**，则所占空间为1
    + 单一继承空类也为1，多重继承空类也为1
    + 如果有**虚函数**（无论多少个虚函数），则所占空间加4(sizeof(int*))，用于存放虚指针（指向虚表的指针），继承同理。
10. 内联函数与宏相比的优势：内联函数要做**类型检查**
11. 内联函数与普通函数相比的优势：`inline`指嵌入代码，在调用函数的地方不是跳转，而是把代码直接嵌入进去。对于短小代码来说`inline`是**空间换时间**（生成的代码会膨胀，但是少了函数调用的开销）
12. 内联函数的适用情况：
    + 该函数不断被重复调用 
    + 该函数只有简单几行，且不包含循环、switch语句
13. `inline`是一种“用于**实现**的关键字”，而不是“用于**声明**的关键字”，即关键字`inline`必须与函数定义体放在一起才能使函数成为内联，仅将`inline`放在函数声明前面不起作用。
    ```c++
    // 以下func函数并非内联函数
    inline void func(int x, int y);
    void func(int x, int y) {
        // do sth
    }
    ```
14. 一个好的编译器会根据函数的定义体自动地取消不值得的内联
