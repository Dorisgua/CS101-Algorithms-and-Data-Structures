#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#include "dsa.h"
#include "dsa.cc"
#define CHK(cond)              \
  do {                         \
    if (!(cond)) return false; \
  } while (0)

int main() {
  // // // directed
  // auto g0 = Graph{7, std::vector{
  //                        Edge{1, 2, 7},
  //                        Edge{1, 3, 3},
  //                        Edge{2, 3, 1},
  //                        Edge{2, 4, 3},
  //                        Edge{3, 5, 10},
  //                        Edge{4, 5, 8},
  //                        Edge{5, 1, 8},
  //                    }};
  // std::vector<Weight> dis(7, 0);
  // g0.sssp(2, dis);
  // for (VertexId i = 1; i <= 7; i++) {
  //   printf("shortest %u->%u: %u", 2, i, (uint32_t)dis[i]);
  // }

  // undirected
  auto g1 = Graph{5, std::vector{
                         // w(1,2) = 7
                         Edge{1, 2, 70},
                         Edge{2, 1, 70},
                         // w(1,3) = 3
                         Edge{1, 3, 3},
                         Edge{3, 1, 3},
                         Edge{1, 3, 70},
                         Edge{3, 1, 70},
                         // w(1,4) = 1
                         Edge{1, 4, 1},
                         Edge{4, 1, 1},
                         // w(2,3) = 3
                         Edge{2, 3, 3},
                         Edge{3, 2, 3},
                         // w(2,5) = 90
                         Edge{2, 5, 70},
                         Edge{5, 2, 70},
                         Edge{2, 3, 2},
                         Edge{3, 2, 2},
                     }};
  std::vector<Edge> mst_edges;
  g1.mst(1, mst_edges);
  for (auto e : mst_edges) {
    printf("edge{%u-%u} wight=%u on MST", e.u, e.v, (uint32_t)e.w);
  }

  return 0;
}