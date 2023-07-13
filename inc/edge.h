#ifndef __EDGE_H__
#define __EDGE_H__

#include <cstdint> 

class Edge {
  public:
    uint64_t from;
    uint64_t to;
    uint64_t weight;
};

#endif 