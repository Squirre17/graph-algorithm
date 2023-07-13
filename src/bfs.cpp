#include "bfs.h"

BFS::BFS(Edge es[], uint64_t num)
    : edges(new vector(es, es + num)),
      n(num)
{}

vector<uint64_t> BFS::run(uint64_t start) {

    queue<uint64_t> q;
    unique_ptr<bool[]> visited(new bool[this->n]);
    vector<uint64_t> visorder; /* visit order */

    for(auto i = 0; i < this->n; i++) {
        visited[i] = false;
    }

    q.push(start);

    while(not q.empty()) {

        auto cur = q.front();q.pop();

        if(visited[cur]) continue;
        visited[cur] = true;
        visorder.push_back(cur);

        for(auto i: this->find_adjnodes(cur)) {
            q.push(i);
        }
    }

    return visorder;
}

/// @brief 从一个结点出发 返回这个顶点所可以到达的所有邻接结点
/// @param from 
/// @return 
vector<uint64_t> BFS::find_adjnodes(uint64_t from) {

    auto &es = *(this->edges);
    vector<uint64_t> v;

    for(auto i = 0; i < this->n; i++) {
        if(es[i].from == from) {
            v.push_back(es[i].to);
        }
    }

    return v;
}