//#pragma once

#include "dsa.h"
#include <iostream>
#include <queue>
using namespace std;
Graph::Graph(VertexId vertices, std::vector<Edge> edges)
    : vertices(vertices), adj(vertices + 1) {
  for (auto e : edges){
    adj[e.u].push_back(e);
    //cout<<e.u<<endl;
  } 
}

void Graph::sssp(VertexId src, std::vector<Weight> &dis) {
/*   // TODO
  //cout<<adj[5].size()<<endl;//1
  int vertices_=vertices;
  int nums_of_adj[vertices_+2];
  int visited[vertices_+2];
  for(int ni = 1; ni <= vertices_; ++ni) {
    visited[ni]=0;
    dis[ni]=9999999;
    nums_of_adj[ni]=adj[ni].size();
  }
  //cout<<dis.size();5
  dis[src]=0;
  visited[src]=1;
  for(int i = 0; i < nums_of_adj[src]; ++i) {
    dis[adj[src][i].v]=adj[src][i].w;
  }
  // for(int i = 1; i <= vertices; ++i) {
  //   cout<<dis[i]<<endl;
  // }
  for(int ni = 1; ni <= vertices_; ++ni) {
    long unsigned int currentDis = 9999999;
    int currentVex=1;
    for(int cvi = 1; cvi <= vertices_; ++cvi) {
      if((!visited[cvi]) && (dis[cvi] < currentDis)) {
        currentDis = dis[cvi];
        currentVex = cvi;
        //cout<<" in if currentVex:"<<currentVex<<endl;
      }
    }
    // for(int i = 1; i <= vertices; ++i) {
    //   cout<<dis[i]<<" ";
    // }
    //cout<<endl;
    visited[currentVex] = 1;
    int w=-1;
    if(nums_of_adj[currentVex]>0){
      w=adj[currentVex][0].v;
    }
    //cout<<"w:"<<w<<endl;
    int size_=0;
    while(w!=-1){
      if((dis[currentVex]+adj[currentVex][size_].w)<dis[w]){
        dis[w]=(dis[currentVex]+adj[currentVex][size_].w);
      }
      size_++;
      if(size_<nums_of_adj[currentVex]){
        w=adj[currentVex][size_].v;
      }
      else{
        w=-1;
      }
    }
  } */
}
constexpr int maxn = 1e5 + 7;
void Graph::mst(VertexId src, std::vector<Edge> &mst_edges) {
  const int vertices_=vertices;
  int nums_of_adj[vertices_+2];
  unsigned long long dist[maxn];
  for(int ni = 1; ni <= vertices_; ++ni) {
    nums_of_adj[ni]=adj[ni].size();
    dist[ni] = INF;
  }
  bool covered[maxn];
  // TODO
  dist[src] = 0;
  covered[src] = true;
  for (int i=0;i<nums_of_adj[src];++i){
    dist[i] = adj[src][i].w;
  }
  auto cnt = 1;
  //auto mst_weight = 0ll;
  while (cnt < vertices_) {
    auto next = 0, w_min = INF;
    for (auto i = 1; i <= vertices_; ++i){
      if (!covered[i] && dist[i] <= w_min) {
        next = i;
        w_min = dist[i];
      }
    }
    assert(next != 0);
    mst_edges.push_back()
    //mst_weight += w_min;
    covered[next] = true;
    ++cnt;
    for (int i=0;i<nums_of_adj[next];++i){
      int weight=adj[next][i].w;
      if (!covered[i] && weight < dist[i]){
        dist[i] = weight;
      }
    }
  }
}