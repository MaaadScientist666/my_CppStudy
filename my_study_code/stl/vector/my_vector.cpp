#include<vector>
#include<iostream>
using namespace std;

// ============ 打印 vector 的函数 ============
// 功能：遍历并输出 vector 中的所有元素
// 参数：vector<int> v - 按值传递（会拷贝整个 vector）
// 注意：使用 != 而不是 <，保证代码通用性
void printVector(vector<int> v) {
    // 使用迭代器遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// ============ 测试函数1：vector 的多种构造方式 ============
void ts01() {
    // ============ 1. 默认构造 + push_back 添加元素 ============
    // 创建空 vector，初始容量通常为 0
    // push_back() 在末尾添加元素，如果容量不足会自动扩容
    // 扩容策略：通常为 2 倍增长（具体取决于实现）
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    printVector(v);

    // ============ 2. 迭代器范围构造 ============
    // 构造函数：vector(InputIterator first, InputIterator last)
    // 用另一个容器的迭代器范围来初始化
    // v.begin() 和 v.end() 指定了 v 的全部元素范围
    // 这相当于拷贝构造，创建 v 的完整副本
    // 特点：可以用于任何容器之间的转换（如 list -> vector）
    vector<int> v2(v.begin(), v.end());
    printVector(v2);
    // ============ 3. 填充构造 ============
    // 构造函数：vector(size_type count, const T& value)
    // 创建包含 count 个元素的 vector，每个元素都初始化为 value
    // vector<int> v3(10, 100)：
    //   - 10：元素个数
    //   - 100：每个元素的初始值
    // 等价于：vector<int> v3 = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    // 特点：所有元素值相同，常用于初始化固定大小的数组
    vector<int> v3(10, 100);
    printVector(v3);

    // ============ 4. 拷贝构造 ============
    // 构造函数：vector(const vector& other)
    // 创建 v3 的完整副本（深拷贝）
    // 执行过程：
    //   1. 分配与 v3 相同大小的内存
    //   2. 将 v3 的所有元素逐个拷贝到新内存
    //   3. 设置大小和容量与 v3 相同
    // 结果：v4 是 v3 的独立副本，修改 v4 不会影响 v3
    vector<int> v4(v3);
    cout<<"v4 = ";
    printVector(v4);
    //-----------------------------------
    cout<<"v4.size= "<<v4.size()<<endl;
    cout<<"v4.capacity= "<<v4.capacity()<<endl;
    v4.resize(15);
    cout<<"v4.size= "<<v4.size()<<endl;
    cout<<"v4.capacity= "<<v4.capacity()<<endl;
    vector<int>(v4).swap(v4);
    cout<<"v4.size= "<<v4.size()<<endl;
    cout<<"v4.capacity= "<<v4.capacity()<<endl;

}

// ============ 主函数 ============
int main(){
    ts01();
}