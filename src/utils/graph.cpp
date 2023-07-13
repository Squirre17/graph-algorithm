#include "graph.h"

Graph::Graph(ssize_t vn, vector<tuple<ssize_t, ssize_t, ssize_t>> edges) :
    graph(vn, vector<Distance>(vn)), 
    node_nr(vn) 
{

    for(auto i = 0; i < vn; i++) {
        for(auto j = 0; j < vn; j++) {
            this->graph[i][j] = Distance::INF;
        }
    }
    
    for(auto &e : edges) {
        auto [from, to, dist] = e; 
        this->graph[from][to] = dist; /* 无向图 */
        this->graph[to][from] = dist; /* 无向图 */
    }
}

// fn Graph::init(vector<tuple<ssize_t, ssize_t, ssize_t>> edges) -> Graph * {
//     for(auto &e : edges) {
//         auto [from, to, dist] = e; 
//         this->graph[from][to] = dist; /* 无向图 */
//         this->graph[to][from] = dist; /* 无向图 */
//     }
//     return this;
// }

fn Graph::dist(ssize_t from, ssize_t to) -> Distance {
    return this->graph[from][to];
}

// /// @brief 遍历所有顶点p 对于p和任意ij 如果 v[i][p] + v[p][j] < v[i][j] 那么就更新 v[i][j] 如果需要 可以用pass[i][j] = p来记录经过的路径
// fn Graph::floyd(ssize_t from, ssize_t to) -> Distance {
//     #define range(n1, n2, n3) for(auto n1 = 0; n1 < this->node_nr; n1++) \
//                                 for(auto n2 = 0; n2 < this->node_nr; n2++) \
//                                 for(auto n3 = 0; n3 < this->node_nr; n3++)

//     auto &g = this->graph;

//     range(p, i, j) {

//         // if(g[i][j] == Distance::INF) {
//             // 
//             // g[i][j] = g[i][p] + g[p][j];
//         // }else {
//             g[i][j] = std::min(g[i][j], g[i][p] + g[p][j]);
//         // }

//     }

//     #undef range
//     return g[from][to];
// }

/// @brief: get all adjacent node(i.e. idx) by `from`
fn Graph::find_all_adjnodes(ssize_t from) -> vector<ssize_t> {

    vector<ssize_t> v;
    auto &g = this->graph;
    
    for(auto i = 0; i < this->node_nr; i++) {
        if(g[from][i] != Distance::INF) {
            v.push_back(i);
        }
    }

    return v;
}