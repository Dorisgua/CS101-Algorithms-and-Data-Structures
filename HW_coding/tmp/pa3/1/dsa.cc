#pragma once

#include "dsa.h"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;//mst还有两个
Graph::Graph(VertexId vertices, std::vector<Edge> edges)
    : vertices(vertices), adj(vertices + 1) {
  for (auto e : edges){
    adj[e.u].push_back(e);
    //cout<<e.u<<endl;
  } 
}
//constexpr 
void Graph::sssp(VertexId src, std::vector<Weight> &dis) {
  //int maxn = 1e5 + 7;
  const int vertices_=vertices;
  int nums_of_adj[vertices_+2];
  //unsigned long long dist[maxn];
  for (auto i = 1; i <= vertices_; ++i){
    dis[i] = INF;
    nums_of_adj[i]=adj[i].size();
  }
  dis[src] = 0;
  std::priority_queue<std::pair<Weight, int>> heap; // (-dist[x], x)
  heap.emplace(0, src);
  while (!heap.empty()) {
    auto [d, x] = heap.top();
    heap.pop();
    d = -d;
    if (d != dis[x]) {
      // if(d>dis[x]){
      //   cout<<"wrong"<<endl;
      // }
      continue;
    }
    for(int i=0;i<nums_of_adj[x];++i){
      if (dis[x] + adj[x][i].w < dis[adj[x][i].v]) {
        dis[adj[x][i].v] = dis[x] + adj[x][i].w;
        heap.emplace(-dis[adj[x][i].v], adj[x][i].v);
      }
    }
  }
}
void Graph::mst(VertexId src, std::vector<Edge> &mst_edges) {
  //int maxn = 1e5 + 7;
  const int vertices_=vertices;
  int nums_of_adj[vertices_+7];
  VertexId parent_x[vertices_+7];
  bool visited[vertices_+7];
  Weight dist[vertices_+7];
  priority_queue<pair<Weight, VertexId>,vector<pair<Weight, VertexId>>,greater<pair<Weight,VertexId>>> heap;
  for (auto i = 0; i <= vertices_+5; ++i){ 
    dist[i] = INF;
    nums_of_adj[i]=adj[i].size();
    //cout<<nums_of_adj[i]<<endl;
    visited[i]=0;
    parent_x[i]=0;
  }
  visited[src]=1;
  dist[src] = 0;
  parent_x[src]=src;
  heap.push(make_pair(0, src));
  while (!heap.empty()) {
    auto [w, x] = heap.top();
    // cout<<"w:"<<w<<","<<"x:"<<x<<endl;
    // cout<<"dist:";
    // for(int i=1;i<=vertices_;i++){
    //   cout<<"dist["<<i<<"]"<<dist[i]<<" ";
    // }
    // //cout<<""
    // cout<<endl;
    if(visited[x]==0){
      Edge src_edge;
      src_edge.u=parent_x[x];
      src_edge.v=x;
      src_edge.w=w;
      visited[x]=1;
      mst_edges.push_back(src_edge);
    }
    heap.pop();
    if (w != dist[x]){
      continue;
    }
    dist[x] = INF;
    for (auto &&[u, v, weight] : adj[x]){//找x的邻边，如果小于这个点的值或者没被cover，heap更新
       if (visited[v]==0&&weight < dist[v]) {
           dist[v] = weight;
           heap.emplace(dist[v], v);
           parent_x[v]=x;
      }
    }
  }
}