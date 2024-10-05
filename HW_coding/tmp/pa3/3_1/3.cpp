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
struct node{
	int x;
	int y;
    bool whether_box;
	node(int a,int b,bool c){
		x=a;
		y=b;
        whether_box=c;
	}
	friend bool operator <(const node xx,const node yy)
	{
		if(xx.x==yy.x)
			return xx.y<yy.y;
		else{
			return xx.x<yy.x;	
		}	
	} 
};
void printa1(priority_queue<node> q1){
    priority_queue<node> q=q1;
    while(!q.empty())
	{
		cout<<q.top().x<<"->"<<q.top().y<<"->"<<q.top().whether_box<<endl;
		q.pop();
	}
	cout<<"end";
}
// void printa2(priority_queue<node2> q2){
//     priority_queue<node2> q=q2;
//     while(!q.empty())
// 	{
// 		cout<<q.top().x<<"->"<<q.top().y<<"->"<<q.top().whether_box<<endl;
// 		q.pop();
// 	}
// 	cout<<"end";
// }
int main() {
    int num_messages,num_boxs;
    int ans=0;
    read(num_messages);
    read(num_boxs);
    priority_queue<node>q;
    int next[1000000000];
    //priority_queue<node2>boxs;
	multiset<int> boxs;
	multiset<int>::iterator it;//返回键值大于等于给定元素的第一个元素
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        q.push(node(di,ai,0));
    }
    for(int i=0;i<num_boxs;++i){
        int ai,di;
        read(ai);
        read(di);
        q.push(node(di,ai,1));
    }
    while(!q.empty())
	{
		if(q.top().whether_box){//如果是box,加入priority_queue<node2>boxs
			boxs.insert(q.top().y);
            num_boxs--;
        }
        else{//如果是message
            num_messages--;
            if(boxs.empty()){}
            else{
                it=boxs.lower_bound(q.top().y);
				if(it!=boxs.end()){
					boxs.erase(it);
					ans++;
				}
            }
        }
        q.pop();
        if(num_boxs<0||num_messages<0){
            break;
        }
	}
    cout<<ans<<endl;
}