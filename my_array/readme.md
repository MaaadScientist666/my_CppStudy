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

## 已知 Bug 与缺陷

> 详情参见上文对话中的完整分析，此处列出关键问题。

| # | 严重度 | 问题 | 位置 |
|---|--------|------|------|
| 1 | 🔴 高 | **自赋值 Use-After-Free**：`a = a` 时先 `delete[]` 再读已释放内存 | `operator=` (第 13–26 行) |
| 2 | 🔴 高 | **`operator[]` 无越界检查**：负数或超大索引导致 UB | `operator[]` (第 35–37 行) |
| 3 | 🟡 中 | **`[] ` 与 `push_back` 数据覆盖**：`array[0]=1` 后紧接着 `push_back(3)` 会静默覆盖 | 设计层 |
| 4 | 🟡 中 | **`operator=` 异常不安全**：先 `delete` 再 `new`，分配失败时对象损坏 | `operator=` (第 13–26 行) |
| 5 | 🟢 低 | **`cur_size+1` 有符号溢出**：`INT_MAX` 时触发 UB | `my_push_back` (第 48 行) |
| 6 | 🟢 低 | **头文件 `using namespace std`**：污染所有包含者的命名空间 | `MyArray.hpp` (第 3 行) |

---

## 当前演示用例行为

```cpp
// main.cpp
MyArray<int> array(3);
array[0] = 1;            // 写到 p_array[0]，cur_size 仍为 0
array.my_push_back(3);   // cur_size→1，p_array[0]=3，把 1 覆盖了
array.my_push_back(4);   // cur_size→2，p_array[1]=4

// 输出：3 4
// 而非可能期望的：1 3 4
```

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

