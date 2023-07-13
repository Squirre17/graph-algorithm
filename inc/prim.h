#ifndef __PRIM_H__
#define __PRIM_H__
#include "common.h"
#include "graph.h"

class Prim {
  public:
    Graph graph;

       Prim(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
    fn find_min_weight_node(vector<u64> &joined, vector<u64> &unjoined) -> std::pair<u64, Distance>;
    fn run() -> uint64_t;
};


#endif