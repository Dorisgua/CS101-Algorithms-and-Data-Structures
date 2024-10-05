#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <set>
#include<stdio.h>
#include<string.h>
using namespace std;
void read(int &x)//从小到大排列
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
void print_set(set<pair<int, int>> a){
    set<pair<int ,int> > ::iterator it;
    cout<<"the set is:"<<endl;
    for(it=a.begin();it!=a.end();it++){
        cout<<it->first<<' '<<it->second<<"\n";
    } 
}
bool comp(const int &a,const int &b)
{
    return a>b;
}
int main() {
    int num_messages,num_boxs;
    read(num_messages);
    read(num_boxs);
    //vector<multiset<int> > heap_messages[10000000];
    //multiset<pair<int, int>> heap_messages;
    pair<int, vector<int>> heap_messages;
    multiset<pair<int, int>> heap_boxs;
    int ans=0;
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        
        //heap_messages[ai].insert(di);
        //num_of_the_message[ai][di]++;
    }
    for(int i=0;i<num_messages;++i){
        sort(heap_messages.second.begin(),heap_messages.second.end(),comp);
    }
    for(int i=0;i<num_boxs;++i){
        int Ai,Di;
        read(Ai);
        read(Di);
        heap_boxs.insert(make_pair(Ai, Di));
    }
    //print_set(heap_messages);
    //print_set(heap_boxs);
    // for(auto i=0;i<num_messages;++i){
    //     multiset<pair<int ,int> > ::iterator it_box;
    //     int ai,di;
    //     ai=heap_messages.begin()->first;
    //     di=heap_messages.begin()->second;
    //     cout<<"ai"<<ai<<endl;
    //     cout<<"di"<<di<<endl;
    //     it_box=heap_boxs.lower_bound(make_pair(ai,di));
    //     if(it_box!=heap_boxs.end()){
    //         if(it_box->second<di){
    //             while(it_box!=heap_boxs.end()&&it_box->second<di){
    //                 it_box++;
    //                 if(it_box==heap_boxs.end()){
    //                     break;
    //                 }
    //             }
    //             if(it_box->second>=di){
    //                 cout<<"ai&&di:"<<ai<<di<<endl;
    //                 cout<<"box:"<<it_box->first<<it_box->second<<endl;
    //                 heap_boxs.erase(it_box);
    //                 ans++; 
    //             }
    //         }
    //         else{
    //             cout<<"ai&&di:"<<ai<<di<<endl;
    //             cout<<"box:"<<it_box->first<<it_box->second<<endl;
    //             //printf("后面接着是 %d %d\n",it_box->first,it_box->second);
    //             heap_boxs.erase(it_box);
    //             ans++; 
    //         }
    //     }
    //     else{}
    //     heap_messages.erase(heap_messages.begin());
    //     if(heap_boxs.empty()){
    //         break;
    //     }
    // }
    // cout<<ans<<endl;
}