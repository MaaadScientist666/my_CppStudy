#include<iostream>
using namespace std;

class student {
public:
    string name;
    string number;
    void set_name() {
        cout<<"请输入学生姓名";
        cin>>name;
        cout<<"学生姓名设置成功"<<"\n";
    }
    void set_number() {
        cout<<"请输入学生学号: ";
        cin>>number;
        cout<<"学生学号设置成功"<<endl;
    }
    void show_student() {
        cout<<"学生的姓名为："<<name;
        cout<<endl<<"学号为："<<number;
    }
};

class cube {
public:
    double len;
public:
    double get_len() {return len;}
    double get_area() {
        return 6*len*len;
    }
    double get_volume() {
        return len*len*len;
    }
    bool is_same(const cube& other) const{
        if (len == other.len) return true;
        else return false;
    }

};

bool is_same_global(cube &c1, cube &c2) {
    if (c1.len == c2.len) return true;
    else return false;
}

class circle {
private:
    int radius;
    int center_x;
    int center_y;
public:
    void set_radius(int len){
        radius = len;
    }
    void set_center(int x, int y) {
        center_x = x;
        center_y = y;
    }
    int get_radius() const {
        return radius;
    }
    int get_center_x() {
        return center_x;
    }
    int get_center_y() {
        return center_y;
    }
};

class point {
public:
    int x,y;
    void set_x(int t_x) {
        x = t_x;
    }
    void set_y(int t_y) {
        y = t_y;
    }
};



int main() {
    circle c1;
    c1.set_center(0, 0);
    c1.set_radius(2);
    point p1;
    p1.set_x(2);
    p1.set_y(0);
    double distance = (p1.x-c1.get_center_x())*(p1.x-c1.get_center_x())+(p1.y-c1.get_center_y())*(p1.y-c1.get_center_y());
    if (distance == c1.get_radius()*c1.get_radius()) {
        cout<<"点在圆上";
    }
    if (distance > c1.get_radius()*c1.get_radius()) {
        cout<<"点在圆外";
    }
    if (distance < c1.get_radius()*c1.get_radius()) {
        cout<<"点在圆内";
    }
}