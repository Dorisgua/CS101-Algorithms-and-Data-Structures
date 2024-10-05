#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <set>
#include<stdio.h>
#include<string.h>
using namespace std;
void read(int &x)//5
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}

struct node{
	int w;
    //int whether_occupied=0;
    vector<int> neighbors;
};
int main(){
    int times;
    read(times);
    for(int count=0;count<times;count++){
    int n,m,A,D;
    read(n);
    read(m);
    read(A);
    read(D);

    const int n_const=n;
    const int maxn = 1e5 + 7;
    int ans=-1;
    node vertices[n_const+7];

    for(int i=1;i<=m;++i){
        int u,v;
        read(u);
        read(v);
        vertices[u].neighbors.push_back(v);
        vertices[v].neighbors.push_back(u);
    }
    for(int i=1;i<=n_const;++i){
        int w;
        read(w);
        vertices[i].w=w;
    }

    if(A==D){//dijistra
        int c[n_const+2];//最晚什么时候到达
        int nums_of_adj[n_const+2];
        int dis[n_const+2];
        bool visited[n_const+2];
        for (auto i = 1; i <= n_const; ++i){
            if(vertices[i].w<vertices[1].w){
                c[i]=maxn;
            }
            else{
                c[i]=-1;//不可能到达
            }
            visited[i]=0;
            dis[i] = maxn;//多少天到达i
            nums_of_adj[i]=vertices[i].neighbors.size();//i的邻居有多少个
        }
        c[1]=0;
        dis[1]=0;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> heap;
        heap.emplace(0, 1);
        while (!heap.empty()) {
            auto [d, x] = heap.top();
            heap.pop();
            if (visited[x]==1){
                continue;
            }
            visited[x]=1;
            //vertices[x].whether_occupied=1;
            if(x==n){
                ans=dis[n];
                break;
            }
            for(int i=0;i<nums_of_adj[x];++i){
                if(vertices[1].w>vertices[vertices[x].neighbors[i]].w&&visited[vertices[x].neighbors[i]]==0){//if(vertices[x].w>=vertices[vertices[x].neighbors[i]].w){
                    if ((dis[x] + 1)< dis[vertices[x].neighbors[i]]){
                        dis[vertices[x].neighbors[i]] = dis[x]+1;
                        heap.emplace(dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    }
}
