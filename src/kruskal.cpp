#include "kruskal.h"


Kruskal::Kruskal(Edge es[], uint64_t an, uint64_t vn) : 
    edges(new vector(es, es + an)), /* 用数组初始化vector */
    ancestor(new uint64_t[vn]),
    vexnum(vn),
    arcnum(an)
{
    auto &e = *(self.edges);
    sort(e.begin(), e.end(), compare_edge);     /* 按weight升序 因为要权值最小的树 覆盖所有结点 */

    for(auto i = 0; i < vn; i++) {
        self.ancestor[i] = i;
    }
}

fn Kruskal::find_unionset(uint64_t idx) -> uint64_t {
    // a[1] a[2] a[3]
    //  1    1    2
    // 当 a[i] == i 的时候就是这个最小生成树的根节点
    if(self.ancestor[idx] == idx) return idx;
    else return self.find_unionset(self.ancestor[idx]);
}

/// @brief join joinee to unionset of x
/// @param x 
/// @param joinee 
fn Kruskal::join_unionset(uint64_t x, uint64_t joinee) -> void {
    self.ancestor[self.find_unionset(joinee)] = self.find_unionset(x);
}

/// @brief 以 边 为基础，先将边从小到大排列，从小到大的添加不构成「环路」的边。
/// @return 
/// @note 这个run没有可重入性 需要清空其他字段才能重入
fn Kruskal::run() -> uint64_t {

    uint64_t tw = 0; /* total weight */
    uint64_t jen = 0; /* joined edge number */

    for(auto i = 0; i < self.arcnum; i++) {

        /* 最小生成树的边数最多为 顶点数-1 */
        if(jen == self.vexnum - 1) break;

        auto &e = *(self.edges);

        /* 不是同一祖先 就加入mgt */
        if(self.find_unionset(e[i].from) != self.find_unionset(e[i].to)) {
            self.join_unionset(e[i].from, e[i].to);
            tw += e[i].weight;
            jen += 1;
        }
    }

    return tw;
}
