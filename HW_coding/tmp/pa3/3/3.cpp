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
    multiset<pair<int, int>> heap_messages;
    multiset<pair<int, int>> heap_boxs;
    int ans=0;
    //int num_of_the_message[100000][100000];
    //vector<vector<int> > V(自定义行数,vector<int>());
    //memset(num_of_the_message,0,sizeof(num_of_the_message));
    //fill(num_of_the_message[0], num_of_the_message[0]+100000*100000, 0);
    //cout<<num_of_the_message[11][9]<<endl;
	// for(int i = 1;i < 10;i++)
	// {
	// 	for(int j = 1;j < 10;j++){
	// 		//printf("%d ",num_of_the_message[i][j]);
    //         cout<<num_of_the_message[i][j];
    //     }
	// 	cout<<endl;
	// }	
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
        if(it_box!=heap_boxs.end()){
            if(it_box->second<di){
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