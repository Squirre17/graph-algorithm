#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include "common.h"
#include "graph.h"
#include "distance.h"

class DijkstraItem {
  public:
    uint64_t node_idx;
    Distance min_dist;  /* 距离start的最小距离 */
    uint64_t prev_node; /* 走前面这个node能经过更少的距离 */
    bool     is_joined; /* 是否已经加入了最小路径图中 */
    DijkstraItem(): 
        min_dist(Distance::INF),
        is_joined(false),
        prev_node(0xdeadbeef)
    {}
};

class Dijkstra {
  public:
    Graph graph;

       Dijkstra(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
    fn run(ssize_t start, ssize_t end) -> uint64_t;
    fn find_shortest_node(unique_ptr<DijkstraItem[]> &tp, uint64_t start) -> int64_t;
};

#endif