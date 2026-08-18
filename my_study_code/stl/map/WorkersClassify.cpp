#include <map>
#include <iostream>
#include <vector>
using namespace std;

// 员工类
class Worker {
public:
    string name;        // 员工姓名
    int salary;         // 员工工资
};

/**
 * 创建10个员工
 * @param v 存储员工的 vector 容器（引用传递，直接修改原容器）
 */
void creat_workers(vector<Worker> &v) {
    string name_seed = "ABCDEFGHIJ";  // 10个字母作为名字后缀

    for (int i = 0; i < 10; i++) {
        Worker worker;

        // 设置员工姓名：员工A、员工B、...、员工J
        worker.name = "员工";
        worker.name += name_seed[i];

        // 随机生成工资：10000 ~ 19999
        worker.salary = rand() % 10000 + 10000;

        // 将员工添加到 vector 中
        v.push_back(worker);
    }
}

/**
 * 将员工随机分配到三个部门
 * @param v  员工 vector（源数据）
 * @param mp 使用 multimap 存储部门-员工映射关系
 *            key: 部门编号 (0=策划, 1=美术, 2=研发)
 *            value: Worker 对象
 *
 * 注意：multimap 允许同一个 key 对应多个 value，
 *      因此一个部门可以拥有多个员工
 */
void set_groups(vector<Worker> &v, multimap<int, Worker> &mp) {
    // 遍历所有员工
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        // 随机生成部门编号：0、1、2
        int dep_id = rand() % 3;

        // 将员工插入到 multimap 中
        // key = dep_id（部门编号），value = *it（员工对象）
        mp.insert(pair<int, Worker>(dep_id, *it));
    }
}

/**
 * 分部门显示所有员工信息
 * @param mp 存储部门-员工映射的 multimap
 *
 * 使用 equal_range() 获取每个部门所有员工的迭代器范围
 * 左闭右开区间 [first, second)
 */
void show_info(multimap<int, Worker> &mp) {
    // ======== 部门0：策划部门 ========
    {
        cout << "dept 0: \n";

        // equal_range(0) 返回 pair<iterator, iterator>
        // first: 指向第一个 key=0 的元素
        // second: 指向第一个 key>0 的元素
        pair<multimap<int, Worker>::iterator,
             multimap<int, Worker>::iterator> range0 = mp.equal_range(0);

        // 遍历 key=0（策划部门）的所有员工
        for (multimap<int, Worker>::iterator it = range0.first;
             it != range0.second;
             it++) {
            cout << "name = " << it->second.name << "   ";
            cout << "salary = " << it->second.salary << "   \n";
        }
    }

    // ======== 部门1：美术部门 ========
    {
        cout << "dept 1: \n";

        pair<multimap<int, Worker>::iterator,
             multimap<int, Worker>::iterator> range0 = mp.equal_range(1);

        for (multimap<int, Worker>::iterator it = range0.first;
             it != range0.second;
             it++) {
            cout << "name = " << it->second.name << "   ";
            cout << "salary = " << it->second.salary << "   \n";
        }
    }

    // ======== 部门2：研发部门 ========
    {
        cout << "dept 2: \n";

        pair<multimap<int, Worker>::iterator,
             multimap<int, Worker>::iterator> range0 = mp.equal_range(2);

        for (multimap<int, Worker>::iterator it = range0.first;
             it != range0.second;
             it++) {
            cout << "name = " << it->second.name << "   ";
            cout << "salary = " << it->second.salary << "   \n";
        }
    }
}

/**
 * 主函数
 */
int main() {
    vector<Worker> v;           // 员工 vector 容器
    multimap<int, Worker> mp;   // 部门-员工映射容器

    // 1. 创建10个员工
    creat_workers(v);

    // 2. 将员工随机分配到三个部门
    set_groups(v, mp);

    // 3. 分部门显示员工信息
    show_info(mp);

    return 0;
}