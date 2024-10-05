#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void read(long long &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
//long long maxn = 1223372036;

long long fa[1000000], height[1000000],val_of_vertices[1000000];
bool visited[1000000];
struct Edge {
  long long  from, to, weight;
};

std::vector<Edge> edges;
//int n, m;
long long  num_of_vertices,num_of_edges;
inline void init() {
  for (auto i = 1; i <= num_of_vertices; ++i) {
    fa[i] = i;
    height[i] = 1;
    visited[i]=1;
  }
}

long long findfa(int x) {
  return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}
long long findfa_and_visited(int x) {
    visited[fa[x]]=0;
    return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}
void merge(int x, int y) {
  x = findfa(x);
  y = findfa(y);
  if (x == y)
    return;
  if (height[x] < height[y])
    fa[x] = y;
  else if (height[y] < height[x])
    fa[y] = x;
  else { // height[x] == height[y]
    fa[x] = y;
    ++height[y];
  }
}
void merge_smaller(long long x, long long y,long long val_of_vertices[]) {//the smaller one is the parent
  x = findfa(x);
  y = findfa(y);
  long long x_val=val_of_vertices[x];
  long long y_val=val_of_vertices[y];
  if (x_val == y_val){
    if(x<=y){
        fa[y] = x;
        //++height[x];
    }
    else{
        fa[x] = y;
        //++height[y];
    }
  }
  else if (x_val > y_val){
    fa[x] = y;
  }
  else{
    fa[y] = x;
  }
}

int main() {
    read(num_of_vertices);
    read(num_of_edges);
    for (auto i =1; i <= num_of_vertices; ++i) {
        long long  val;
        read(val);
        val_of_vertices[i]=val;
        edges.push_back({.from = i, .to = i, .weight = val});
    }
    for (auto i = 1; i <= num_of_edges; ++i) {
        long long  x, y, z;
        read(x);
        read(y);
        read(z);
        if(x>y){
            int m=x;
            x=y;
            y=m;
        }
        edges.push_back({.from = x, .to = y, .weight = z});
    }
  // C++20: std::ranges::sort(edges, {}, &Edge::weight);
  std::sort(edges.begin(), edges.end(),
            [](const auto &a, const auto &b) { return a.weight < b.weight; });
  init();
  long long mst_weight = 0;
  int count=0;
  for (auto &&[u, v, w] : edges) {
    if (u!=v){
        long long father_of_u=findfa(u);
        long long father_of_v=findfa(v);
        if (visited[father_of_u] == 0&&visited[father_of_v] != 0) {
            mst_weight += w;
            fa[father_of_v]=father_of_u;
            findfa_and_visited(v);
            //visited[v]=0;
            //visited[father_of_v] = 0;
            count++;
        }
        else if(visited[father_of_v] == 0&&visited[father_of_u] != 0){
            mst_weight += w;
            fa[father_of_u]=father_of_v;
            findfa_and_visited(u);
            //visited[u]=0;
            //visited[father_of_u] = 0;
            count++;
        }
        else if(visited[father_of_v] == 0&&visited[father_of_u] == 0){
        }
        else if(visited[father_of_v] != 0&&visited[father_of_u] != 0){
            if (father_of_u != father_of_v) {
                mst_weight += w;
                merge_smaller(u,v,val_of_vertices);
                count++;
            }
            else{
            }
        }
        else{}
        //continue;
    }
    else{// (u==v) 
        if(visited[findfa(u)]==1){
            mst_weight += w;
            visited[findfa(u)]=0;
            count++;
        }
    }
    // if(count>=num_of_vertices){
    //     break;
    // }
    // cout << u<<" "<<v << std::endl;
    // cout<<"visited:";
    // for (auto i = 1; i <= num_of_vertices; ++i) {
    //     cout << visited[i]<<" ";
    // }
    // cout<<std::endl;
    // cout<<"fa:";
    // for (auto i = 1; i <= num_of_vertices; ++i) {
    //     long long val1=fa[i];
    //     cout << val1<<" ";
    // }
    // cout<<std::endl;
    // cout<<"mst_weight:";
    // cout << mst_weight << std::endl;
  }
  std::cout << mst_weight << std::endl;
  return 0;
}