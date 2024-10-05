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
int main() {
    int num_messages,num_boxs;
    read(num_messages);
    read(num_boxs);
    multiset<pair<int, <cmp_greater>int>> heap_messages;//multiset可以自行排序，按照第一个从小到大，再到第二个从小到大
    multiset<pair<int, int>> heap_boxs;
    int ans=0;
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        heap_messages.insert(make_pair(ai,di));
        //num_of_the_message[ai][di]++;
    }
    for(int i=0;i<num_boxs;++i){
        int Ai,Di;
        read(Ai);
        read(Di);
        heap_boxs.insert(make_pair(Ai, Di));
    }
    //print_set(heap_messages);
    //print_set(heap_boxs);
    
    //cout<<heap_boxs.begin()->first<<endl;
    //cout<<heap_boxs.begin()->second<<endl;
    //it_box=heap_boxs.upper_bound(make_pair(heap_messages.begin()->first,heap_messages.begin()->second));
    for(int i=0;i<num_messages;++i){
        multiset<pair<int ,int> > ::iterator it_box;
        int ai,di;
        ai=heap_messages.begin()->first;
        di=heap_messages.begin()->second;
        it_box=heap_boxs.lower_bound(make_pair(ai,di));
        if(it_box!=heap_boxs.end()){//找得到比Ai大的
            if(it_box->second<di){//如果di比Di大
                while(it_box!=heap_boxs.end()&&it_box->second<di){
                    it_box++;
                    if(it_box==heap_boxs.end()){
                        break;
                    }
                }
                if(it_box->second>=di){
                    cout<<"ai&&di:"<<ai<<di<<endl;
                    cout<<"box:"<<it_box->first<<it_box->second<<endl;
                    heap_boxs.erase(it_box);
                    ans++; 
                }
            }
            else{
                cout<<"ai&&di:"<<ai<<di<<endl;
                cout<<"box:"<<it_box->first<<it_box->second<<endl;
                //printf("后面接着是 %d %d\n",it_box->first,it_box->second);
                heap_boxs.erase(it_box);
                ans++; 
            }
        }
        else{
            //cout<<"not good"<<endl;
        }
        heap_messages.erase(heap_messages.begin());
        //print_set(heap_boxs);
        if(heap_boxs.empty()){
            break;
        }
    }
    cout<<ans<<endl;
}