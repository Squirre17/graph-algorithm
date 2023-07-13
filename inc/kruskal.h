#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__
#include "common.h"
#include "edge.h"


class Kruskal {
  private:
    unique_ptr<vector<Edge>> edges;
    unique_ptr<uint64_t[]> ancestor;
    uint64_t n;/* side len */
    uint64_t vexnum;
    uint64_t arcnum;
    static bool compare_edge(const Edge &e1, const Edge &e2) {
        return e1.weight < e2.weight;
    }
  public:
       Kruskal(Edge es[], uint64_t an, uint64_t vn);
    fn find_unionset(uint64_t idx) -> uint64_t;
    fn join_unionset(uint64_t x, uint64_t joinee) -> void;
    fn run() -> uint64_t;
};

#endif 