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
	}
	friend bool operator <(const node xx,const node yy)
	{
		if(xx.x==yy.x)
			return xx.y>yy.y;
		else{
			return xx.x>yy.x;	
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
// int main()
// {
//     priority_queue<node> q;
// 	q.push(node(3,4,1));
// 	q.push(node(4,5,1));
//     q.push(node(3,4,1));
//     q.push(node(3,8,1));
// 	q.push(node(4,7,1));
//     q.push(node(4,2,1));
// 	q.push(node(3,3,1));
// 	while(!q.empty())
// 	{
// 		cout<<q.top().x<<"->"<<q.top().y<<endl;
// 		q.pop();
// 	}
// 	cout<<"end";
// 	return 0;
// }
int main() {
    int num_messages,num_boxs;
    int ans=0;
    read(num_messages);
    read(num_boxs);
    priority_queue<node> message_queue;
    priority_queue<node> boxs_queue;
    multiset<int> boxs;
    multiset<int>::iterator it;
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        message_queue.push(node(ai,di,0));
    }
    for(int i=0;i<num_boxs;++i){
        int ai,di;
        read(ai);
        read(di);
        boxs_queue.push(node(ai,di,1));
    }
    while(!boxs_queue.empty()){
        cout<<"boxs_queue:"<<endl;
        printa1(boxs_queue);
        cout<<"message_queue:"<<endl;
        printa1(message_queue);
        cout<<"ans:"<<ans<<endl;
        cout<<endl;
        while(!message_queue.empty()){
            if(boxs_queue.top().x>=message_queue.top().x){
                boxs.insert(message_queue.top().y);
                message_queue.pop();
            }
            else{
                break;
            }
        }
        it=boxs.upper_bound(boxs_queue.top().y);
        if(it==boxs.begin()){}//如果it是第一个或者没有比盒子y小的
        // if(*boxs.end()<=boxs_queue.top().y){//*boxs.end()<=boxs_queue.top().y
        //     it=boxs.end();
        //     boxs.erase(it);
		// 	ans++;
        // }
        else{
            it--;
            boxs.erase(it);
			ans++;
        }
        boxs_queue.pop();
    }
    cout<<ans<<endl;
}