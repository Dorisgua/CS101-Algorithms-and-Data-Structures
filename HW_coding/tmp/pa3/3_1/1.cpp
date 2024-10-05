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
struct node2{
	int x;
	int y;
    bool whether_box;
	node2(int a,int b,bool c){
		x=a;
		y=b;
        whether_box=c;
	}
	friend bool operator <(const node2 xx,const node2 yy)
	{
		// if(xx.x==yy.x)
		// 	return xx.y>yy.y;
		// else{
		// 	return xx.x>yy.x;	
		// 	}	

        // if(xx.y==yy.y)
		// 	return xx.x>yy.x;
		// else{
		// 	return xx.y>yy.y;	
		// 	}	
        return xx.y>yy.y;	
	} 
};
// int main()
// {
//     priority_queue<node2>q;
// 	q.push(node2(3,4,1));
// 	q.push(node2(4,5,1));
//     q.push(node2(3,4,1));
//     q.push(node2(3,8,1));
// 	q.push(node2(4,7,1));
//     q.push(node2(4,2,1));
// 	q.push(node2(3,3,1));
// 	while(!q.empty())
// 	{
// 		cout<<q.top().x<<"->"<<q.top().y<<endl;
// 		q.pop();
// 	}
// 	cout<<"end";
// 	return 0;
// }
void printa1(priority_queue<node> q1){
    priority_queue<node> q=q1;
    while(!q.empty())
	{
		cout<<q.top().x<<"->"<<q.top().y<<"->"<<q.top().whether_box<<endl;
		q.pop();
	}
	cout<<"end";
}
void printa2(priority_queue<node2> q2){
    priority_queue<node2> q=q2;
    while(!q.empty())
	{
		cout<<q.top().x<<"->"<<q.top().y<<"->"<<q.top().whether_box<<endl;
		q.pop();
	}
	cout<<"end";
}
int main() {
    int num_messages,num_boxs;
    int ans=0;
    read(num_messages);
    read(num_boxs);
    priority_queue<node>q;
    priority_queue<node2>boxs;
    for(int i=0;i<num_messages;++i){
        int ai,di;
        read(ai);
        read(di);
        q.push(node(ai,di,0));
        //heap_messages.insert(make_pair(ai,di));
        //num_of_the_message[ai][di]++;

    }
    for(int i=0;i<num_boxs;++i){
        int ai,di;
        read(ai);
        read(di);
        q.push(node(ai,di,1));
    }
    //printa1(q);
    while(!q.empty())
	{
		if(q.top().whether_box){//如果是box,加入priority_queue<node2>boxs
            boxs.push(node2(q.top().x,q.top().y,1));
        }
        else{//如果是message,和priority_queue<node2>boxs的第一个配对
            // cout<<"the boxs before match:";
            // printa2(boxs);
            //break;
            if(boxs.empty()){}
            else{
                if(boxs.top().y>=q.top().y){
                    ans++;
                    boxs.pop();
                }
                else{
                    priority_queue<node2> boxs2;//作为接住的
                    while(!boxs.empty()){
                        if(boxs.top().y>=q.top().y){
                            ans++;
                            boxs.pop();
                            break;
                        }
                        else{                        
                            boxs2.push(node2(boxs.top().x,boxs.top().y,1));
                            boxs.pop();
                        }
                    }
                    while(!boxs2.empty()){
                        boxs.push(node2(boxs2.top().x,boxs2.top().y,1));
                        boxs2.pop();
                    }
                }
            }
            // cout<<"the boxs after match:";
            // printa2(boxs);
        }
        q.pop();
        //printa1(q);
	}
    cout<<ans<<endl;
}