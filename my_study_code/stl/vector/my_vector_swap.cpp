#include<vector>
#include <iostream>
using namespace std;

void printVector(vector<int> &v) {
    // 使用迭代器遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void ts01() {
    // ============ 1. 创建并填充大量数据 ============
    vector<int> v1;

    // 循环添加 100000 个元素
    // push_back() 会自动扩容，通常采用 2 倍增长策略
    // 这会导致多次内存重新分配
    for (int i = 0; i < 100000; i++) {
        v1.push_back(i);
    }

    // 输出当前状态
    cout << "v1的容量 = " << v1.capacity() << endl;
    // 输出：v1的容量 = 131072（或 131072，取决于实现）
    // 注意：容量通常是 2 的幂次，刚好能容纳 100000 个元素
    // 常见实现：
    //   - GCC: 131072 (2^17)
    //   - MSVC: 131072 (2^17)
    //   - Clang: 131072 (2^17)

    cout << "v1的大小 = " << v1.size() << endl;
    // 输出：v1的大小 = 100000

    // ============ 2. resize 缩小容量 ============
    // resize(3) 将元素个数缩小到 3 个
    // 执行过程：
    //   1. 保留前 3 个元素（0, 1, 2）
    //   2. 删除第 4 个及之后的元素（3 到 99999）
    //   3. size 变为 3
    //   4. capacity 保持不变！
    //
    // 结果：虽然只需要 3 个元素，但仍然占用 131072 个元素的内存
    v1.resize(3);

    cout << "v1的容量 = " << v1.capacity() << endl;
    // 输出：v1的容量 = 131072（容量没变！）
    // 内存依然被占用，巨大的浪费！

    cout << "v1的大小 = " << v1.size() << endl;
    // 输出：v1的大小 = 3（只有 3 个元素）

    // ============ 3. 使用 swap 技巧释放多余内存 ============
    // vector<int>(v1).swap(v1);
    // 这是一个经典的内存缩容技巧！
    //
    // 分步执行：
    //   1. vector<int>(v1) - 创建一个临时 vector，用 v1 拷贝构造
    //      临时 vector 的 size = 3, capacity = 3（恰好匹配）
    //   2. .swap(v1) - 交换临时 vector 和 v1 的内容
    //      交换后：
    //        - v1 获得临时 vector 的容量（3）
    //        - 临时 vector 获得 v1 的大容量（131072）
    //   3. 临时 vector 析构，释放 131072 个元素的内存
    //
    // 结果：v1 现在拥有恰好 3 个元素的容量，大内存被释放！
    vector<int>(v1).swap(v1);

    cout << "v1的容量 = " << v1.capacity() << endl;
    // 输出：v1的容量 = 3（内存被完全释放！）

    cout << "v1的大小 = " << v1.size() << endl;
    // 输出：v1的大小 = 3（元素保持不变）
}

int main() {
    ts01();
}