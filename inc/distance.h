#ifndef __DISTANCE_H__
#define __DISTANCE_H__

#include "common.h"

class Distance {
  public:
    uint64_t dist;
    static const uint64_t INF = std::numeric_limits<uint64_t>::max();
    Distance(uint64_t distance);
    Distance();
    static Distance from(uint64_t distance);

    Distance operator+(const Distance &other) ;

    Distance operator=(uint64_t other);
    
    bool operator==(uint64_t other);

    bool operator==(const Distance &other);

    bool operator!=(uint64_t other);

    bool operator!=(const Distance &other);
    bool operator>(uint64_t other);

    bool operator>(const Distance &other) const;
    
    bool operator<(const Distance &other) const;

    bool operator>=(uint64_t other);
    bool operator<=(const Distance &other) const;
};

#endif

