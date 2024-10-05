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
	int w;
    int whether_occupied=0;
    vector<int> neighbors;
	// node(int a,int b){

	// }
	// friend bool operator <(const node xx,const node yy)
	// {
	// 	if(xx.x==yy.x)
	// 		return xx.y<yy.y;
	// 	else{
	// 		return xx.x<yy.x;	
	// 		}	
	// } 
};
int main(){
    int times;
    read(times);
    for(int count=0;count<times;count++){
    int n,m,A,D;
    int ans=-1;
    read(n);
    read(m);
    read(A);
    read(D);
    const int n_const=n;
    //vector<node> vertices[n_const+7];
    node vertices[n_const+7];
    for(int i=1;i<=m;++i){
        int u,v;
        read(u);
        read(v);
        vertices[u].neighbors.push_back(v);
        vertices[v].neighbors.push_back(u);
    }
    for(int i=1;i<=n;++i){
        int w;
        read(w);
        vertices[i].w=w;
    }
    if(A==D){//dijistra
        int c[n_const+2];
        int maxn = 1e5 + 7;
        int nums_of_adj[n_const+2];
        int dis[n_const+2];
        for (auto i = 1; i <= n_const; ++i){
            if(vertices[i].w<vertices[1].w){
                c[i]=maxn;
            }
            else{
                c[i]=-1;
            }
            dis[i] = maxn;
            nums_of_adj[i]=vertices[i].neighbors.size();
        }
        c[1]=1;
        dis[1]=0;
        std::priority_queue<std::pair<int, int>> heap; // (-dist[x], x)
        heap.emplace(0, 1);
        while (!heap.empty()) {
            auto [d, x] = heap.top();
            heap.pop();
            d = -d;
            if (d != dis[x]){
                continue;
            }
            for(int i=0;i<nums_of_adj[x];++i){
                if(c[vertices[x].neighbors[i]]==-1){//if(vertices[x].w>=vertices[vertices[x].neighbors[i]].w){
                    if (dis[x] + 1< dis[vertices[x].neighbors[i]]){
                        dis[vertices[x].neighbors[i]] = dis[x]+1;
                        heap.emplace(-dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                    }
                }
            }
        }
        ans=dis[n];
    }
        // if(vertices[1]>=vertices[n]){
        //     //ans=

        // }
        // else{}
    cout<<ans<<endl;
    }
}
