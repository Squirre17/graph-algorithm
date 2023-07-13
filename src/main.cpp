#include "common.h"
#include "edge.h"  
#include "bfs.h"
#include "dfs.h"
#include "floyd.h"
#include "dijkstra.h"
#include "kruskal.h"
#include "prim.h"

#include <assert.h>




#define ut(name) (name##_ut) 

void ut(bfs)() {
    // ref: doc/dfs.gif
    Edge edges[] = {
        {0, 1, 0},
        {0, 2, 0},
        {1, 3, 0},
        {1, 4, 0},
        {3, 7, 0},
        {4, 7, 0},
        {2, 5, 0},
        {2, 6, 0},
    };

    BFS bfs(edges, sizeof(edges)/sizeof(Edge));
    vector<uint64_t>visorder = bfs.run(0);

    // show(visorder);
    // show(result);
    assert(visorder[0] == 0);

    auto b = visorder.begin();
    vector<uint64_t>  second(b + 1, b + 3);
    sort(second.begin(), second.end());
    vector<uint64_t> r2 = {1, 2};
    assert(second == r2);

    vector<uint64_t> third(b + 3, b + 7);
    sort(third.begin(), third.end());
    vector<uint64_t> r3 = {3, 4, 5, 6};
    assert(third == r3);

    assert(visorder.back() == 7);
    ok("bfs passed");
}

enum Node {
    A = 0,
    B,
    C,
    D
};

void ut(dfs)() {
    Edge edges[] = {
        {0, 1, 0},
        {0, 2, 0},
        {1, 3, 0},
        {1, 4, 0},
        {3, 7, 0},
        {4, 7, 0},
        {2, 5, 0},
        {2, 6, 0},
    };

    DFS dfs(edges, sizeof(edges)/sizeof(Edge));
    vector<uint64_t>visorder = dfs.run(0);

    // show(visorder);
    // show(result);
    vector<uint64_t> result = {0, 2, 6, 5, 1, 4, 7, 3};
    assert(result == visorder);
    // assert(visorder.back() == 7);
    ok("dfs passed");
}

void ut(floyd)() {

    vector<tuple<ssize_t, ssize_t, ssize_t>> edges = {
        {A, B, 2},
        {A, D, 6},
        {B, D, 2},
        {B, C, 3},
        {C, D, 2},
    };

    Floyd floyd {4, edges};


    assert(floyd.run(0, 1) == 2);
    assert(floyd.run(0, 2) == 5);
    assert(floyd.run(0, 3) == 4);
    assert(floyd.run(1, 2) == 3);
    assert(floyd.run(3, 2) == 2);
    ok("floyd passed");
}

void ut(dijkstra)() {

    vector<tuple<ssize_t, ssize_t, ssize_t>> edges = {
        {A, B, 2},
        {A, D, 6},
        {B, D, 2},
        {B, C, 3},
        {C, D, 2},
    };

    Dijkstra dijkstra {4, edges};

    assert(dijkstra.run(A, B) == 2);
    assert(dijkstra.run(A, C) == 5);
    assert(dijkstra.run(A, D) == 4);
    assert(dijkstra.run(B, C) == 3);
    assert(dijkstra.run(D, C) == 2);

    ok("dijkstra passed");
}

void ut(kruskal)() {
    Edge edges[] = {
        {A, B, 3},
        {A, D, 7},
        {B, D, 4},
        {B, C, 2},
        {C, D, 6},
        {C, A, 3},
    };

    Kruskal k(edges, sizeof(edges)/sizeof(Edge), 4);
    assert(k.run() == 9);
    ok("kruskal passed");
}

void ut(prim)() {
    vector<tuple<ssize_t, ssize_t, ssize_t>> edges = {
        {A, B, 3},
        {A, D, 7},
        {B, D, 4},
        {B, C, 2},
        {C, D, 6},
        {C, A, 3},
    };

    Prim p(4, edges);
    auto r = p.run();
    dbg("result is %lx", r);
    assert(r == 9);
    ok("prim passed");
}

void uts() {
    ut(bfs)();
    ut(dfs)();
    ut(floyd)();
    ut(dijkstra)();
    ut(kruskal)();
    ut(prim)();
}
int main(int argc, char** argv)
{
    // ut5();
    uts();
    return 0;
}
