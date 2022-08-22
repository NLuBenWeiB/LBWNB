#include <cstdio>
#include <vector>

typedef long long ll;

const int MaxN = 200005;

int n, fa[MaxN];

struct Graph {
    struct Edge { int to; Edge *next; } edge[MaxN], *head[MaxN], *top = edge;

    inline void add_edge(int u, int v) {
        *++top = Edge{ .to = v, .next = head[u] };
        head[u] = top;
    }
} tree;

int sz[MaxN], dfn[MaxN], dft = 0;

void dfs(int u) {
    sz[u] = 1;
    dfn[u] = ++dft;

    for (Graph::Edge *e = tree.head[u]; e; e = e->next) {
        int v = e->to;
        dfs(v);
        sz[u] += sz[v];
    }
}

struct FenwickTree {
    ll arr[MaxN];

    inline void modify(int pos, int val) {
        for (; pos <= n; pos += pos & -pos) arr[pos] += val;
    }

    inline ll query(int pos) const {
        ll res = 0;
        for (; pos; pos -= pos & -pos) res += arr[pos];
        return res;
    }

    inline ll query(int l, int r) const {
        return query(r) - query(l - 1);
    }
} T;

int main() {
    int query_cnt;
    scanf("%d%d", &n, &query_cnt);

    for (int i = 2; i <= n; ++i) {
        scanf("%d", fa + i);
        tree.add_edge(fa[i], i);
    }

    dfs(1);

    while (query_cnt--) {
        int op, u, x;
        scanf("%d%d", &op, &u);

        if (op == 1) {
            scanf("%d", &x);
            T.modify(dfn[u], x);
        } else if (op == 2) {
            printf("%lld\n", T.query(dfn[u], dfn[u] + sz[u] - 1));
        }
    }
    return 0;
}
