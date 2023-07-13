#include "prim.h"
#include "assert.h"

Prim::Prim(ssize_t n, vector<tuple<ssize_t, ssize_t, ssize_t>> edges) :
    graph(n, edges)
{

}

fn Prim::find_min_weight_node(vector<u64> &joined, vector<u64> &unjoined) -> std::pair<u64, Distance> {

    assert(not joined.empty());
    assert(not unjoined.empty());

    auto &e = self.graph.graph;

    u64 min_idx  = unjoined[0];
    Distance min = e[joined[0]][unjoined.back()];

    for(auto j: joined) {
        for(auto uj: unjoined) {
            if(e[j][uj] < min){
                min_idx = uj;
                min = e[j][uj];
            }
        }
    }

    return std::pair(min_idx, min);
} 

void show(vector<uint64_t> v) {
    for(auto &i: v) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

fn Prim::run() -> u64 {

    u64  tw = 0; /* total weight */
    auto vn = self.graph.node_nr;

    vector<u64> joined = {0};
    vector<u64> unjoined;
    for(auto i = 1; i < vn; i++) {
        unjoined.push_back(i);
    }
    
    while(not unjoined.empty()) {

        auto [cand, dist] = self.find_min_weight_node(joined, unjoined);

        unjoined.erase(
            std::remove(unjoined.begin(), unjoined.end(), cand), unjoined.end()
        );

        joined.push_back(cand);
        tw += dist.dist;

    }
    return tw;
}