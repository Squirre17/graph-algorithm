#ifndef __DFS_H__
#define __DFS_H__

#include "common.h"
#include "edge.h" 

class DFS {
  private:
    unique_ptr<vector<Edge>> edges;
    uint64_t n;
    vector<uint64_t> find_adjnodes(uint64_t from);

  public:
                     DFS(Edge es[], uint64_t num);
    vector<uint64_t> run(uint64_t start);
};

#endif 