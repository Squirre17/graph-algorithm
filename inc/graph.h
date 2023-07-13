#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "common.h"
#include "distance.h"

class Graph {
  private:
  public:
    vector<vector<Distance>> graph;
    uint64_t node_nr;

       Graph(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
    // fn init(vector<tuple<ssize_t, ssize_t, ssize_t>> edges) -> Graph *;
    fn dist(ssize_t from, ssize_t to) -> Distance;
    fn floyd(ssize_t from, ssize_t to) -> Distance;
    fn find_all_adjnodes(ssize_t from) -> vector<ssize_t>;
};

#endif