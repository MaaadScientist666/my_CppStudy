#include<string>      // 包含 string 类定义，提供 std::string 的所有功能
#include<iostream>    // 包含输入输出流，提供 std::cout, std::endl 等
using namespace std;  // 使用标准命名空间，避免每次写 std:: 前缀

int main() {
    // ============ 1. 默认构造函数 ============
    // 调用 string 的默认构造函数：string()
    // 创建一个空字符串，内部通常指向一个静态的空字符串常量
    // 或者指向一个空的小缓冲区（取决于 SSO 实现）
    // 此时：s1.size() == 0，s1.empty() == true
    string s1;
    cout<<"s1 = "<<s1<<endl;  // 输出空字符串（什么也不显示）
    // 注意：虽然 s1 为空，但它是有效的 std::string 对象
    // 不是 nullptr，可以安全地访问 .c_str() 返回空字符串指针

    // ============ 2. 定义C风格字符串 ============
    // const char* 是指向字符数组（C风格字符串）的指针
    // "hello world" 是字符串字面量，存储在程序的只读数据段
    // 字符串以 '\0' 结尾，长度为 11 个字符（不包括 '\0'）
    const char * str = "hello world";
    cout<<"str = "<<str<<endl;  // cout 会从 str 指向的地址开始，直到遇到 '\0' 为止

    // ============ 3. 从C字符串构造 ============
    // 调用构造函数：string(const char* s)
    // 执行过程：
    //   1. 计算 s 的长度：strlen(str) = 11
    //   2. 分配内存（如果字符串较长，使用堆；如果很短，使用SSO缓冲区）
    //   3. 逐字符拷贝：'h','e','l','l','o',' ','w','o','r','l','d'
    //   4. 在末尾添加 '\0' 终止符
    // 结果：s2 包含了 "hello world" 的独立拷贝
    // 注意：s2 和 str 指向不同的内存地址（s2 有自己的内存）
    string s2(str);
    cout<<"s2 = "<<s2<<endl;  // 输出 "hello world"

    // ============ 4. 拷贝构造函数 ============
    // 调用构造函数：string(const string& other)
    // 执行过程：
    //   1. 获取 other 的长度（已经知道是 11）
    //   2. 分配新的内存（与 other 独立的内存空间）
    //   3. 将 other 的所有字符复制到新内存
    //   4. 设置大小和容量
    // 结果：s3 是 s2 的完整副本，两者完全独立
    //
    // ⚠️ 重要：这是深拷贝（Deep Copy），不是浅拷贝
    // 修改 s3 不会影响 s2，反过来也一样
    //
    // 💡 性能提示：如果对象很大，拷贝构造代价较高
    // 可以用移动语义避免拷贝：string s3(std::move(s2));
    string s3(s2);
    cout<<"s3 = "<<s3<<endl;  // 输出 "hello world"

    // ============ 额外演示：验证独立性 ============
    // 这行代码证明 s2 和 s3 是独立的（可选演示）
    // s2[0] = 'H';  // 修改 s2
    // cout<<"s2 = "<<s2<<endl;  // 输出 "Hello world"
    // cout<<"s3 = "<<s3<<endl;  // 仍然输出 "hello world"（不受影响）

    return 0;  // 程序结束
    // 在 main 函数返回时，s1, s2, s3 的析构函数会自动调用
    // 释放各自占用的内存（RAII 资源管理）
}