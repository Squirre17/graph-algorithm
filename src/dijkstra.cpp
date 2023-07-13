#include "dijkstra.h"
#include "assert.h"



Dijkstra::Dijkstra(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges) :
    graph(n, edges)
{

}
/// @brief 
/// @param start 
/// @param end 
/// @return
/// @note 注意这里有两个值 一个是graph中的距离 一个是dt中的最小值 我们只更新dt表
fn Dijkstra::run(ssize_t start, ssize_t end) -> uint64_t {

    auto nnr = self.graph.node_nr;
    unique_ptr<DijkstraItem[]> dt(new DijkstraItem[nnr]); /* dijkstra table */

    auto g = self.graph.graph;

    dt[start].prev_node = start;
    dt[start].min_dist  = 0;
    dt[start].is_joined = 0;

    for(auto n: self.graph.find_all_adjnodes(start)) {
        dt[n].prev_node = start;
        dt[n].min_dist  = g[start][n];
    }

    for(auto i = 0; i < nnr; i++) {/* 每次拉入一个结点到我们的已经完成的最小图中来 */

        if(i == start) continue;

        uint64_t idx = (uint64_t)self.find_shortest_node(dt, start);
        if((int64_t)idx < 0)
            continue;

        /* 加入最短图中 */
        dt[idx].is_joined = true;

        /* 更新所有相邻结点 */
        for(auto j: self.graph.find_all_adjnodes(idx)) {

            /* j途经idx比j原先走到start的路径更少开销的话 */
            if(g[j][idx] + dt[idx].min_dist < dt[j].min_dist) {
                dt[j].min_dist  = g[j][idx] + dt[idx].min_dist;
                dt[j].prev_node = idx;
            }

        }

    }

    return dt[end].min_dist.dist;
}

/// @brief find shortest node index which isn't joined to graph 
/// @param tp 
/// @param start 
/// @return node idx if success, otherwise -1 if not found any node,
fn Dijkstra::find_shortest_node(unique_ptr<DijkstraItem[]> &tp, uint64_t start) -> int64_t {

    Distance min = Distance::INF;
    uint64_t idx = 0xdeadbeef;
    auto nnr = self.graph.node_nr;
    auto &g  = self.graph.graph;

    for(auto i = 0; i < nnr; i++) {

        if(i == start) continue;

        if((not tp[i].is_joined) and (tp[i].min_dist < min)) {
            min = tp[i].min_dist;
            idx = i;
        }
    }

    // assert(idx != 0xdeadbeef);
    if (idx == 0xdeadbeef)
        return -1;

    return idx;
}
