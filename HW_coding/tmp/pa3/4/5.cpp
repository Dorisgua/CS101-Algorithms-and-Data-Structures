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
    const int maxn = 1000000007;
    int ans=-1;
    node vertices[n_const+3];

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
    //cout<<"3/(D-A):"<<(3/(D-A))<<endl;
    if(A==D){//dijistra
        int c[n_const+3];//最晚什么时候到达
        int nums_of_adj[n_const+3];
        int dis[n_const+3];
        bool visited[n_const+3];
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
            if(x==n){
                ans=dis[n];
            }
            //vertices[x].whether_occupied=1;
            for(int i=0;i<nums_of_adj[x];++i){
                if(c[vertices[x].neighbors[i]]!=-1&&visited[vertices[x].neighbors[i]]==0){//if(vertices[x].w>=vertices[vertices[x].neighbors[i]].w){
                    if ((dis[x] + 1)< dis[vertices[x].neighbors[i]]){
                        dis[vertices[x].neighbors[i]] = dis[x]+1;
                        heap.emplace(dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                    }
                }
            }
        }
    }
    else if(A<D){//dijistra
        //int times_of_days[n_const+3];
        int times_of_days=0;
        int nums_of_adj[n_const+3];
        int dis[n_const+3];
        bool visited[n_const+3];
        for (auto i = 1; i <= n_const; ++i){
            visited[i]=0;
            dis[i] = maxn;//多少天到达i
            nums_of_adj[i]=vertices[i].neighbors.size();//i的邻居有多少个
            //int times_of_days[i]=0;
        }
        dis[1]=0;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> heap;
        heap.emplace(0, 1);
        while (!heap.empty()) {
            auto [d, x] = heap.top();
            heap.pop();
            if (visited[x]==1){
                continue;
            }
            //cout<<"x"<<x;
            //cout<<"dis[x]:"<<dis[x]<<endl;
            //int times_of_daysofx=
            if(dis[x]!=maxn){
                times_of_days=dis[x];
            }
            visited[x]=1;
            if(x==n){
                ans=dis[n];
            }
            //cout<<"times_of_days:"<<times_of_days<<endl;
            for(int i=0;i<nums_of_adj[x];++i){
                //cout<<"not in if--v:"<<vertices[x].neighbors[i]<<"x:"<<x<<endl;
                if(vertices[vertices[x].neighbors[i]].w<vertices[1].w&&visited[vertices[x].neighbors[i]]==0){
                    if(vertices[1].w+A*times_of_days>vertices[vertices[x].neighbors[i]].w+D*times_of_days){
                        //cout<<"x:"<<x;
                        //cout<<"dis[x]:"<<dis[x]<<endl;
                        if ((dis[x]+1) < dis[vertices[x].neighbors[i]]){
                            dis[vertices[x].neighbors[i]] = dis[x]+1;
                            //cout<<"in if--";
                            //cout<<"v:"<<vertices[x].neighbors[i]<<" ";
                            //cout<<"dis[v]:"<<dis[vertices[x].neighbors[i]];
                            //cout<<"end if--"<<endl;
                            //times_of_days[vertices[x].neighbors[i]]=times_of_days[x]+1;
                            heap.emplace(dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                        }
                    }
                }
            }
        }
    }
    else{//A>D
        int times_of_days=0;
        int Max_strength=vertices[1].w+(n_const-1)*A;
        int days_need_of_vertices[n_const+3];
        int nums_of_adj[n_const+3];
        int dis[n_const+3];
        bool visited[n_const+3];
        int added_each_time=A-D;
        for (auto i = 1; i <= n_const; ++i){
            if(vertices[i].w<=vertices[1].w){
                days_need_of_vertices[i]=0;
            }
            else{
                days_need_of_vertices[i]=(vertices[i].w-vertices[1].w)/(A-D)+1;
            }
            visited[i]=0;
            dis[i] = maxn;//多少天到达i
            nums_of_adj[i]=vertices[i].neighbors.size();//i的邻居有多少个
        }
        dis[1]=0;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> heap;
        heap.emplace(0, 1);
        while (!heap.empty()) {
            auto [d, x] = heap.top();
            heap.pop();
            if (visited[x]==1){
                continue;
            }
            if(dis[x]!=maxn){
                times_of_days=dis[x];
            }
            visited[x]=1;
            if(x==n){
                ans=dis[n];
            }
            for(int i=0;i<nums_of_adj[x];++i){
                if(visited[vertices[x].neighbors[i]]==0){
                    if(vertices[vertices[x].neighbors[i]].w+times_of_days*D<Max_strength){
                        if(vertices[1].w+added_each_time*times_of_days>vertices[vertices[x].neighbors[i]].w){
                            if ((dis[x]+1) < dis[vertices[x].neighbors[i]]){
                                dis[vertices[x].neighbors[i]] = dis[x]+1;
                                heap.emplace(dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                            }
                        }
                        else if(vertices[1].w+added_each_time*times_of_days<=vertices[vertices[x].neighbors[i]].w){
                            if(days_need_of_vertices[vertices[x].neighbors[i]]<=1+(dis[vertices[x].neighbors[i]]+1-vertices[1].w)/added_each_time){
                                dis[vertices[x].neighbors[i]] = days_need_of_vertices[vertices[x].neighbors[i]];
                                heap.emplace(dis[vertices[x].neighbors[i]],vertices[x].neighbors[i]);
                            }
                        }
                    }
                }
            }

        }
    }
    cout<<ans<<endl;
    }
}