#ifndef __BFS_H__
#define __BFS_H__

#include "edge.h"
#include "common.h"


class BFS {
  private:
    unique_ptr<vector<Edge>> edges;
    uint64_t n;
    
    vector<uint64_t> find_adjnodes(uint64_t from);
  public:
                     BFS(Edge es[], uint64_t num);
    vector<uint64_t> run(uint64_t start);
};


#endif