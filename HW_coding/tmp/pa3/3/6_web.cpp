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
int main() {
    int ans=0;
    int num_messages,num_boxs;
    read(num_messages);
    read(num_boxs);
    auto cmp = [&](const auto& a, const auto& b) {
        if(a.first<b.first){
            return a.first>b.first ;
        }
        if(a.first==b.first){
            return a.second  < b.second ;
        }
        else{
            return a.first>b.first ;
        }
	};
	vector <pair<int, int>> heap_messages;
    multiset<pair<int, int>> heap_boxs;
	for (int i = 0; i < num_messages; i++) {
		pair<int, int> a;
        read(a.first);
        read(a.second);
		heap_messages.push_back(a);
	}
    for(int i=0;i<num_boxs;++i){
        int Ai,Di;
        read(Ai);
        read(Di);
        heap_boxs.insert(make_pair(Ai, Di));
    }
	// cout << "排序前：" << endl;
	// for (auto pair:heap_messages) {
	// 	cout << pair.first << " " << pair.second << "  |  ";
	// }
	priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)> PairQueue(cmp);
	//decltype是自动识别类型
	for (auto pair : heap_messages) {
		PairQueue.push(pair);
	}
	cout << endl;
	//cout << "排序后：" << endl;
	while (!PairQueue.empty()) {
		auto pair_ = PairQueue.top();
		//cout << pair.first << " " << pair.second << "  |  ";
		//
        multiset<pair<int ,int> > ::iterator it_box;
        int ai,di;
        ai=pair_.first;
        di=pair_.second;
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
                    //cout<<"ai&&di:"<<ai<<di<<endl;
                    //cout<<"box:"<<it_box->first<<it_box->second<<endl;
                    heap_boxs.erase(it_box);
                    ans++; 
                }
            }
            else{
                //cout<<"ai&&di:"<<ai<<di<<endl;
                //cout<<"box:"<<it_box->first<<it_box->second<<endl;
                //printf("后面接着是 %d %d\n",it_box->first,it_box->second);
                heap_boxs.erase(it_box);
                ans++; 
            }
        }
        else{
            //cout<<"not good"<<endl;
        }
        PairQueue.pop();
        if(heap_boxs.empty()){
            break;
        }
	}
    cout<<ans<<endl;

}
    