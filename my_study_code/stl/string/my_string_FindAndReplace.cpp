#include<string>      // 包含 string 类定义
#include<iostream>    // 包含输入输出流
using namespace std;  // 使用标准命名空间

// ============ 测试函数1：字符串查找 ============
void ts01() {
    // 创建一个包含所有小写字母的字符串
    // 索引: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    // 字符: a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
    string s1 = "abcdefghijklmnopqrstuvwxyz";

    // ============ 1.1 从左往右查找 (find) ============
    // find() 从索引0开始，从左向右搜索子串 "de"
    // 返回值类型：size_t (无符号整数)
    // 找到返回第一次出现的位置索引，没找到返回 string::npos (通常是 -1)
    int pos = s1.find("de");

    // ?? 注意：这里用 -1 判断是否找到
    // 但 pos 是 int 类型，而 find() 返回 size_t (无符号)
    // 更好的写法是：if (pos == string::npos)
    if (pos == -1) {
        cout<<"未找到!";
    } else {
        // "de" 在 s1 中的位置：
        // a b c d e f g ...
        // 0 1 2 3 4 5 6
        //       ↑ ↑
        //       d e  ← 索引3和4
        // 所以 pos = 3
        cout<<"pos = "<<pos<<endl;  // 输出：pos = 3
    }

    // ============ 1.2 从右往左查找 (rfind) ============
    // rfind() 从字符串末尾开始，从右向左搜索子串 "de"
    // 但注意：虽然是从右向左搜索，比较字符时仍然是从左到右！
    // 在这个字符串中，"de" 只出现一次，所以结果和 find() 相同
    pos = s1.rfind("de");
    if (pos == -1) {
        cout<<"未找到!";
    } else {
        // 因为字符串中只有一个 "de"，所以结果仍然是 3
        cout<<"pos = "<<pos<<endl;  // 输出：pos = 3
    }

    // ? 演示多个匹配时 find() 和 rfind() 的区别：
    // 如果 s1 = "abcdeabcde"
    // find("de")  → 返回 3  (第一个匹配)
    // rfind("de") → 返回 8  (最后一个匹配)
}

// ============ 测试函数2：字符串替换 ============
void ts02() {
    // 创建一个测试字符串
    // 索引: 0 1 2 3 4 5 6
    // 字符: a b c d e f g
    string s1 = "abcdefg";
    cout<<"s1 = "<<s1<<endl;  // 输出：s1 = abcdefg

    // ============ replace() 函数 ============
    // 函数原型：string& replace(size_t pos, size_t count, const char* str)
    // 参数说明：
    //   - pos: 起始位置索引 (从0开始)
    //   - count: 要替换的字符数
    //   - str: 替换成的新字符串

    // s1.replace(2, 4, "LOLO");
    // 执行过程：
    // 1. 从索引2开始（即字符 'c' 的位置）
    // 2. 替换 4 个字符："c", "d", "e", "f"
    // 3. 替换为："LOLO" (4个字符)
    //
    // 替换前：
    // 索引: 0  1  2  3  4  5  6
    // 字符: a  b  c  d  e  f  g
    //          ↑  ↑  ↑  ↑  ↑
    //          |  |  |  |  |
    //          pos=2     count=4
    //          要替换的字符: c d e f
    //
    // 替换后：
    // 索引: 0  1  2  3  4  5  6  7  8  9
    // 字符: a  b  L  O  L  O  g
    //          ↑  ↑  ↑  ↑  ↑
    //          替换为 "LOLO"
    //
    // 结果：原字符串从 "abcdefg" 变为 "abLOLOg"
    s1.replace(2, 4, "LOLO");
    cout<<"s1 = "<<s1<<endl;  // 输出：s1 = abLOLOg
}

int main() {
    // 调用不同的测试函数
    // ts01();  // 取消注释可测试查找功能
    ts02();     // 测试替换功能
    return 0;   // 程序结束
}