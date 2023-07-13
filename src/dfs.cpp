#include "common.h"
#include "edge.h" 
#include "dfs.h"


DFS::DFS(Edge es[], uint64_t num)
        : edges(new vector(es, es + num)),
          n(num)
{}

vector<uint64_t> DFS::find_adjnodes(uint64_t from) {

    auto &es = *(this->edges);
    vector<uint64_t> v;

    for(auto i = 0; i < this->n; i++) {
        if(es[i].from == from) {
            v.push_back(es[i].to);
        }
    }

    return v;
}

vector<uint64_t> DFS::run(uint64_t start) {

    vector<uint64_t> stack;
    unique_ptr<bool[]> visited(new bool[this->n]);
    vector<uint64_t> visorder; /* visit order */

    for(auto i = 0; i < this->n; i++) {
        visited[i] = false;
    }

    stack.push_back(start);

    while(not stack.empty()) {

        auto cur = stack.back();stack.pop_back();

        if(visited[cur]) continue;
        visited[cur] = true;
        visorder.push_back(cur);

        for(auto i: this->find_adjnodes(cur)) {
            stack.push_back(i);
        }
    }

    return visorder;
}