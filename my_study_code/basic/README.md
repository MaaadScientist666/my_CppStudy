# C++ 基础语法练习合集

本目录收录了 C++ 基础语法的学习示例代码，内容从入门到进阶，涵盖引用、结构体、类与对象、运算符重载、继承、多态、模板、STL 容器、文件操作等主题，最后以一个「通讯录管理系统」综合项目收尾。

## 目录结构

| 文件 | 主题 | 说明 |
| --- | --- | --- |
| `main.cpp` | 引用与指针 | `swap01` 引用传参 / `swap02` 指针传参 |
| `my_reference.cpp` | 引用 | 引用作函数返回值（返回静态局部变量） |
| `my_func.cpp` | 函数重载 | `int &` 与 `const int &` 参数的重载选择 |
| `my_struct.cpp` | 结构体 | 结构体嵌套（老师-学生）与数组赋值 |
| `my_struct2.cpp` | 结构体 | 结构体数组按 `age` 冒泡排序 |
| `my_new.cpp` | 动态内存 | `new` / `delete`、堆区数组 |
| `my_BubbleSort.cpp` | 算法 | 数组冒泡排序 |
| `my_student_class.cpp` | 类与对象 | `student` / `cube` / `circle` / `point` 及圆上点判断 |
| `my_this.cpp` | this 指针 | 链式调用 `AddPerson` |
| `mt_ConstructorAndDestructor.cpp` | 构造与析构 | 深拷贝、对象成员构造析构顺序 |
| `my_OperatorReload.cpp` | 运算符重载 | `+`、前置/后置 `++`、`<<`（成员 + 全局） |
| `my_OperatorReloadFUZHI.cpp` | 赋值运算符重载 | 深拷贝 `operator=`、自赋值保护、链式赋值 |
| `my_OperatorReloadGUANXI.cpp` | 关系运算符重载 | `<`、`>`、`==` |
| `my_OperatorReloadHANSHU.cpp` | 仿函数 | `operator()` 函数调用运算符重载 |
| `my_inheritance.cpp` | 继承 | 继承权限、同名成员、菱形继承 |
| `my_Polymorphism.cpp` | 多态 | 虚函数与动态绑定 |
| `calculator.cpp` | 多态 | 抽象类 + 纯虚函数实现简易计算器 |
| `my_ComputerClass.cpp` | 多态案例 | 组装电脑（CPU/显卡/内存 接口化设计） |
| `my_template.cpp` | 模板 | 函数模板、类模板、类模板继承 |
| `my_iterator.cpp` | STL | `vector` 容器与多种遍历方式 |
| `my_file.cpp` | 文件操作 | 文本文件读写（四种读取方式） |
| `my_file_binary.cpp` | 文件操作 | 二进制文件读写（对象序列化） |
| `my_txl.cpp` | 综合项目 | 通讯录管理系统 |

## 环境要求

- C++ 编译器（GCC / MinGW / MSVC 均可）
- 建议使用 C++11 及以上标准

## 编译运行示例

各示例均为独立的 `.cpp` 文件，可用任意编译器单独编译运行：

```bash
# GCC / MinGW
g++ -std=c++11 main.cpp -o main && ./main

# MSVC（命令行）
cl /EHsc main.cpp && main.exe
```

> 注：`my_txl.cpp`（通讯录管理系统）为交互式控制台程序，编译后直接运行并按菜单提示操作即可。

## 内容要点概览

### 1. 基础语法
- **引用**：本质是指针常量，常用于传参避免拷贝、作返回值需注意不能返回局部变量。
- **函数重载**：同一函数名不同参数，`const` 也可构成重载。
- **结构体**：自定义数据类型，支持嵌套与数组。

### 2. 内存管理
- `new` / `delete`：堆区内存分配与释放，成对使用。
- **深拷贝 vs 浅拷贝**：成员含指针时需自定义拷贝/赋值/析构，避免重复释放（见 `mt_ConstructorAndDestructor.cpp`、`my_OperatorReloadFUZHI.cpp`）。

### 3. 面向对象
- **封装**：类与对象、访问权限 `public/protected/private`。
- **继承**：继承方式、同名成员、菱形继承问题。
- **多态**：虚函数 + 动态绑定，抽象类（纯虚函数）作接口。
- **运算符重载**：加号、递增、赋值、关系、函数调用运算符。
- **this 指针**：指向当前对象，可实现链式调用。

### 4. 泛型与 STL
- **模板**：函数模板、类模板、类模板继承。
- **vector 容器**：迭代器遍历、嵌套容器、存放对象/对象指针。

### 5. 文件操作
- **文本文件**：`ofstream` / `ifstream`，多种读取方式。
- **二进制文件**：`write` / `read` 进行对象级读写。

## 学习建议

建议按以下顺序学习：

1. 先看「基础语法」与「内存管理」部分，理解引用、指针、函数重载与堆内存。
2. 再进入「面向对象」，按 封装 → 继承 → 多态 的路径，配合运算符重载加深理解。
3. 掌握「泛型与 STL」与「文件操作」。
4. 最后用 `my_txl.cpp` 通讯录管理系统做综合练习，将结构体、函数、流程控制融会贯通。
