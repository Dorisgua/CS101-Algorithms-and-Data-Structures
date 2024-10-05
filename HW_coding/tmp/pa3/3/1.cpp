#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
void read(int &x)//过了前四个点
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main() {
    int num_messages,num_boxs;
    read(num_messages);
    read(num_boxs);
    priority_queue<std::pair<int, int>> heap_messages;
    priority_queue<std::pair<int, int>> heap_boxs;
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        heap_messages.emplace(ai, di);
    }
    for(int i=0;i<num_boxs;++i){
        int Ai,Di;
        read(Ai);
        read(Di);
        heap_boxs.emplace(Ai, Di);
    }
    for(int i=0;i<num_messages;++i){
        cout<<heap_messages.top().first<<endl;
        heap_messages.pop();
        //cout<<heap_messages.pop()<<endl;
    }
    for(int i=0;i<num_boxs;++i){
        cout<<heap_boxs.top().first<<" "<<heap_boxs.top().second<<endl;
        heap_boxs.pop();
    }
}