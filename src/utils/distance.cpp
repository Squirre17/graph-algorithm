#include "distance.h"

Distance::Distance(uint64_t distance): dist(distance) {}
Distance::Distance(): dist(Distance::INF) {}
// static Distance Distance::from(uint64_t distance) {}

Distance Distance::operator+(const Distance &other) {
    if(this->dist == Distance::INF or other.dist == Distance::INF) {
        return Distance::INF;
    }
    return this->dist + other.dist;
}

Distance Distance::operator=(uint64_t other) {
    this->dist = other;
}

bool Distance::operator==(uint64_t other) {
    return this->dist == other;
}

bool Distance::operator==(const Distance &other) {
    return this->dist == other.dist;
}

bool Distance::operator!=(uint64_t other) {
    return this->dist != other;
}

bool Distance::operator!=(const Distance &other) {
    return this->dist != other.dist;
}

bool Distance::operator>(uint64_t other) {
    return this->dist > other;
}

bool Distance::operator>(const Distance &other) const {
    return this->dist > other.dist;
}

bool Distance::operator<(const Distance &other) const {
    return this->dist < other.dist;
}


bool Distance::operator>=(uint64_t other) {
    return this->dist >= other;
}

bool Distance::operator<=(const Distance &other) const {
    return this->dist <= other.dist;
}