# MyArray — 自定义动态数组

## 项目概览

一个小型 C++ 教学项目，实现了一个简易的动态数组模板类 `MyArray<T>`，模拟 `std::vector` 的部分功能，用于学习和理解 C++ 中的动态内存管理、运算符重载、拷贝语义以及模板编程。

- **语言标准**：C++20
- **构建系统**：CMake 4.3 + Ninja
- **文件数**：2 个源文件（`MyArray.hpp` + `main.cpp`）

---

## 文件结构

```
my_array/
├── CMakeLists.txt          # CMake 构建配置
├── MyArray.hpp             # 数组模板类头文件（声明+实现）
├── main.cpp                # 入口 / 简单演示用例
└── cmake-build-debug/      # 构建产物（自动生成）
```

---

## 类设计

### 模板参数

| 参数 | 含义 |
|------|------|
| `T` | 数组中存储的元素类型 |

### 成员变量

| 成员 | 类型 | 说明 |
|------|------|------|
| `array_size` | `int` | 数组的总容量（已分配的内存槽位数） |
| `cur_size` | `int` | 当前已存储的元素个数 |
| `p_array` | `T*` | 指向堆上分配的数组内存 |

### 对外接口

```cpp
template<class T>
class MyArray {
public:
    // 构造 & 析构
    MyArray(int capacity);                       // 构造：指定容量，在堆上分配 T[capacity]
    MyArray(const MyArray &my_array);            // 拷贝构造：深拷贝
    ~MyArray();                                  // 析构：释放堆内存

    // 运算符重载
    MyArray& operator=(const MyArray &my_array); // 拷贝赋值：深拷贝
    T&       operator[](int index);              // 下标访问（无越界检查）

    // 元素操作
    void my_push_back(const T &val);             // 尾部追加元素
    void my_pop();                               // 尾部弹出元素（仅 cur_size--）

    // 成员变量（public，便于教学演示直接访问）
    int  array_size;
    T   *p_array;
    int  cur_size;
};
```

### 缺失的功能

以下是 `std::vector` 具备但 `MyArray` 尚未实现的常见功能：

- 默认构造函数（无参）
- 移动构造 / 移动赋值
- `size()` / `capacity()` 等只读访问器
- `begin()` / `end()` 迭代器
- `at()` 带越界检查的下标访问
- 自动扩容（`push_back` 在容量不足时仅打印提示，不扩容）

---


## 构建 & 运行

```bash
# 配置（在项目根目录下）
cmake -B cmake-build-debug -G Ninja

# 编译
cmake --build cmake-build-debug

# 运行
./cmake-build-debug/my_array.exe
```

---

## 适用场景

这是一个**学习型项目**，适合：
- 练习 C++ 动态内存管理（`new[]` / `delete[]`）
- 理解拷贝构造 vs 拷贝赋值的区别
- 练习运算符重载语法
- 培养代码审查和 bug 分析能力

不适合用于生产环境。

