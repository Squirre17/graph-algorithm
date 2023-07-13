#ifndef __FLOYD_H__
#define __FLOYD_H__
#include "common.h"
#include "distance.h"
#include "graph.h"

// #define min(x, y) (((x) > (y)) ? (y) : (x))
// class DijkstraTable {
//   public:
//     uint64_t node_idx;
//     Distance min_dist;  /* 距离start的最小距离 */
//     uint64_t prev_node; /* 走前面这个node能经过更少的距离 */
//     bool     is_joined; /* 是否已经加入了图中 */
//     DijkstraTable(): min_dist(Distance::INF) {}
// };


// class Graph {
//   private:
//     vector<vector<Distance>> graph;
//     uint64_t side_len;
//   public:

//     Graph(ssize_t n);
//     Graph*          init(vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
//     Distance        dist(ssize_t from, ssize_t to);
//     Distance        floyd(ssize_t from, ssize_t to);
//     vector<ssize_t> adjacent(ssize_t from);


//     /// @brief find shortest node index which isn't joined to graph 
//     /// @param tp 
//     /// @param start 
//     /// @return 
//     // uint64_t find_shortest_node(unique_ptr<DijkstraTable[]> &tp, uint64_t start);

//     // void update_adjcent(unique_ptr<DijkstraTable[]> &tp, uint64_t from) {

//     //     for(auto i : this->adjacent(from)) {

//     //     }
//     // }
//     // bool is_adjcent(uint64_t from, uint64_t to);


// };
class Floyd {
  private:
    Graph graph;
  public:
       Floyd(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
    fn run(ssize_t from, ssize_t to) -> Distance;
};


#endif