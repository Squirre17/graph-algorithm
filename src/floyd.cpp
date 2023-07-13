#include "common.h"
#include "distance.h"
#include "floyd.h"

class DijkstraItem {
  public:
    uint64_t node_idx;
    Distance min_dist;  /* 距离start的最小距离 */
    uint64_t prev_node; /* 走前面这个node能经过更少的距离 */
    bool     is_joined; /* 是否已经加入了图中 */
    DijkstraItem(): min_dist(Distance::INF) {}
};


Floyd::Floyd(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges) :
    graph(n, edges)
{

}



/// @brief 遍历所有顶点p 对于p和任意ij 如果 v[i][p] + v[p][j] < v[i][j] 那么就更新 v[i][j] 如果需要 可以用pass[i][j] = p来记录经过的路径
fn Floyd::run(ssize_t from, ssize_t to) -> Distance {

    #define range(n1, n2, n3, len) \
                for(auto n1 = 0; n1 < len; n1++) \
                for(auto n2 = 0; n2 < len; n2++) \
                for(auto n3 = 0; n3 < len; n3++)

    auto &g = self.graph.graph;

    range(p, i, j, self.graph.node_nr) {
        g[i][j] = std::min(g[i][j], g[i][p] + g[p][j]);
    }

    return g[from][to];
}
