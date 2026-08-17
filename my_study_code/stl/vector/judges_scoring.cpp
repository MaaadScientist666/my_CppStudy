#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class player {
public:
    player() {
        avg_score = 0;
        sum_score = 0;
    }
    deque<int> score;
    double avg_score;
    int sum_score;
};

int main() {
    vector<player> p(5);
    for (vector<player>::iterator it = p.begin();it!=p.end();it++) {
        for (int i=0;i<10;i++) {
            cout<<"请输入第"<<i<<"位评委的评分：";
            int t_score;
            cin>>t_score;
            (*it).score.push_back(t_score);
        }
        sort((*it).score.begin(),(*it).score.end());
        (*it).score.pop_back();
        (*it).score.pop_front();
        for (deque<int>::iterator it2 = (*it).score.begin();it2!=(*it).score.end();it2++) {
            (*it).sum_score += (*it2);
        }
        (*it).avg_score = (*it).sum_score/8.0;
    }
    int i = 0;
    for (vector<player>::iterator it = p.begin();it!=p.end();it++) {
        cout<<"第"<<i<<"位选手的总分为:"<<(*it).sum_score<<endl;
        cout<<"第"<<i<<"位选手的平均分为:"<<(*it).avg_score<<endl;
        i++;
    }
}
