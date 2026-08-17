#include<string>      // 包含 string 类定义
#include<iostream>    // 包含输入输出流
using namespace std;  // 使用标准命名空间

int main() {
    // ============ 1. 使用 += 运算符拼接字符串字面量 ============
    // string s1 = "我";  调用构造函数创建包含 "我" 的字符串
    string s1 = "我";
    
    // s1 += "爱玩游戏:";  使用 += 运算符追加字符串字面量
    // 等价于：s1.operator+=("爱玩游戏:")
    // 执行过程：
    //   1. 计算当前长度（1个中文字符，UTF-8编码占3字节）
    //   2. 计算追加后的总长度
    //   3. 如果容量不足，重新分配内存（通常扩容2倍）
    //   4. 将 "爱玩游戏:" 的字符拷贝到 s1 末尾
    //   5. 更新长度和终止符
    s1 += "爱玩游戏:";
    cout<<"s1 = "<<s1<<endl;  // 输出：s1 = 我爱玩游戏:
    
    // ============ 2. 使用 += 运算符拼接另一个 string 对象 ============
    string s2 = "DOTA2 LOL";
    
    // s1 += s2;  使用 += 运算符追加另一个 string 对象
    // 等价于：s1.operator+=(s2)
    // 与追加字符串字面量的区别：
    //   - 追加字面量：需要先计算 strlen()
    //   - 追加 string：直接使用 s2.size()，效率更高
    // 执行过程与上面类似，只是数据源是 s2 的内部缓冲区
    s1 += s2;
    cout<<"s1 = "<<s1<<endl;  // 输出：s1 = 我爱玩游戏:DOTA2 LOL
    
    // ============ 3. 使用 append() 方法（基础用法） ============
    string s3 = "I";
    
    // s3.append(" LOVE ");  追加字符串字面量
    // 等价于：s3 += " LOVE "
    // append() 方法有多个重载版本，提供更灵活的控制
    s3.append(" LOVE ");
    cout<<"s3 = "<<s3<<endl;  // 输出：s3 = I LOVE 
    
    // ============ 4. append() 的带长度版本 ============
    // s3.append("GAME abcde", 4); 
    // 重载版本：append(const char* str, size_t count)
    // 从 "GAME abcde" 中取前 4 个字符进行追加
    // 执行过程：
    //   1. 从字符串字面量 "GAME abcde" 中取前 4 个字符："GAME"
    //   2. 检查容量是否足够
    //   3. 将这 4 个字符追加到 s3 末尾
    //   4. 更新长度
    // 
    // ?? 注意：这里不会自动添加空格，而是精确取指定数量的字符
    // 结果：s3 从 "I LOVE " 变为 "I LOVE GAME"
    s3.append("GAME abcde", 4);
    cout<<"s3 = "<<s3<<endl;  // 输出：s3 = I LOVE GAME
    
    // ============ 5. append() 从另一个 string 取子串 ============
    // s3.append(s2, 5, 4);
    // 重载版本：append(const string& str, size_t subpos, size_t sublen)
    // 参数说明：
    //   - s2: 源字符串对象 "DOTA2 LOL"
    //   - 5: 从索引 5 开始（从 0 开始计数）
    //   - 4: 取 4 个字符
    // 
    // s2 = "DOTA2 LOL"
    //       索引: 0 1 2 3 4 5 6 7 8
    //       字符: D O T A 2   L O L
    //                ↑ 从索引5开始
    //                ↓ 取4个字符
    //       结果: " LOL"（注意：索引5是空格，所以包含前导空格）
    // 
    // 执行过程：
    //   1. 检查索引 5 是否在 s2 范围内（s2.size() = 9，索引5 < 9，合法）
    //   2. 计算实际取的长度（4 个字符：" LOL"）
    //   3. 检查 s3 容量是否足够
    //   4. 将 " LOL" 追加到 s3 末尾
    //   5. 更新长度
    // 
    // ? 如果 sublen 超过字符串剩余长度，会取到末尾
    // ? 如果 subpos 超出范围，会抛出 std::out_of_range 异常
    s3.append(s2, 5, 4);
    cout<<"s3 = "<<s3<<endl;  // 输出：s3 = I LOVE GAME LOL
    
    return 0;  // 程序结束，所有 string 对象自动析构释放内存
}