#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <set>
#include<stdio.h>
#include<string.h>
using namespace std;
void read(long long &x)//从小到大排列
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main() {
    int ans=0;
    long long num_messages,num_boxs;
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
	vector <pair<long long, long long>> heap_messages;
    multiset<pair<long long, long long>> heap_boxs;
	for (int i = 0; i < num_messages; i++) {
		pair<long long, long long> a;
        read(a.first);
        read(a.second);
		heap_messages.push_back(a);
	}
    for(int i=0;i<num_boxs;++i){
        long long Ai,Di;
        read(Ai);
        read(Di);
        heap_boxs.insert(make_pair(Ai, Di));
    }
	// cout << "排序前：" << endl;
	// for (auto pair:heap_messages) {
	// 	cout << pair.first << " " << pair.second << "  |  ";
	// }
	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, decltype(cmp)> PairQueue(cmp);
	//decltype是自动识别类型
	for (auto pair : heap_messages) {
		PairQueue.push(pair);
	}
	//cout << endl;
	cout << "排序后：" << endl;
	while (!PairQueue.empty()) {
		auto pair_ = PairQueue.top();
		//cout << pair_.first << " " << pair_.second << "  |  ";
		cout <<"message:" <<pair_.first << " " << pair_.second << "  |  "<<endl;
        multiset<pair<long long ,long long> > ::iterator it_box;
        long long ai,di;
        ai=pair_.first;
        di=pair_.second;
        it_box=heap_boxs.lower_bound(make_pair(ai,di));
        if(it_box!=heap_boxs.end()){//找得到比Ai大的
            if(it_box->second<di){//如果di比Di大
                while(it_box!=heap_boxs.end()&&it_box->second<di){
                    it_box++;
                    if(it_box==heap_boxs.end()){
                        cout<<"not find"<<endl;
                        break;
                    }
                }
                if(it_box->second>=di){
                    //cout<<"ai&&di:"<<ai<<di<<endl;
                    //cout<<"box:"<<it_box->first<<it_box->second<<endl;
                    cout <<"box:" <<it_box->first << " " << it_box->second << "  |  "<<endl;
                    heap_boxs.erase(it_box);
                    ans++; 
                }
            }
            else{
                //cout<<"ai&&di:"<<ai<<di<<endl;
                //cout<<"box:"<<it_box->first<<it_box->second<<endl;
                //printf("后面接着是 %d %d\n",it_box->first,it_box->second);
                cout <<"box:" <<it_box->first << " " << it_box->second << "  |  "<<endl;
                heap_boxs.erase(it_box);
                ans++; 
            }
        }
        else{
            cout<<"not find"<<endl;
        }
        PairQueue.pop();
        if(heap_boxs.empty()){
            break;
        }
	}
    cout<<ans<<endl;

}
    