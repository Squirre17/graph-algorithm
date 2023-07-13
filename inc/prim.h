#ifndef __PRIM_H__
#define __PRIM_H__
#include "common.h"
#include "graph.h"

/// @brief 创建两个集合 一个是加入的 一个是未加入的 以结点进行划分 每次从未加入的结点中选出一个 它的距离到已加入的所有结点的距离最小
///        然后把它加入 已加入的集合
class Prim {
  public:
    Graph graph;

       Prim(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges);
    fn find_min_weight_node(vector<u64> &joined, vector<u64> &unjoined) -> std::pair<u64, Distance>;
    fn run() -> uint64_t;
};


#endif