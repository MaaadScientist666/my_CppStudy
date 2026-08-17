#include<iostream>
using namespace std;

class Cpu {
public:
    virtual void calculate() = 0;
};

class Card {
public:
    virtual void display() = 0;
};

class Memory {
public:
    virtual void storage() = 0;
};

class Computer {
private:
    Cpu *cpu; //cpu指针
    Card *card; //显卡指针
    Memory *memory; //内存指针
public:
    Computer(Cpu *cpu,Card *card,Memory *memory) {
        this->cpu = cpu;
        this->card = card;
        this->memory = memory;
    } //构造函数
    void work() {
        this->cpu->calculate();
        this->card->display();
        this->memory->storage();
    } //工作函数，调用接口
    ~Computer() {
        if (this->cpu != nullptr) {
            delete this->cpu;
            this->cpu = nullptr;
        }
        if (this->card != nullptr) {
            delete this->card;
            this->card = nullptr;
        }
        if (this->memory != nullptr) {
            delete this->memory;
            this->memory = nullptr;
        }
    } // 析构函数
};

class IntelCpu : public Cpu {
public:
    void calculate() override {
        cout<<"Intel Cpu is working"<<endl;
    }
};

class IntelCard:public Card {
public:
    void display() override {
        cout<<"Intel Card is working"<<endl;
    }
};

class IntelMemory:public Memory {
public:
    void storage() override {
        cout<<"Intel Memory is working"<<endl;
    }

};

class AmdCpu : public Cpu {
public:
    void calculate() override {
        cout<<"Amd Cpu is working"<<endl;
    }
};

class AmdCard:public Card {
public:
    void display() override {
        cout<<"Amd Card is working"<<endl;
    }
};

class AmdMemory:public Memory {
public:
    void storage() override {
        cout<<"Amd Memory is working"<<endl;
    }

};

int main() {
    Cpu * intel_cpu = new IntelCpu;
    Card * intel_card = new IntelCard;
    Memory * amd_memory = new AmdMemory;
    Computer c1(intel_cpu,intel_card,amd_memory);
    c1.work();

}