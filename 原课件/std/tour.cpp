#include <cstdio>
#include <algorithm>

typedef long long ll;

const int MaxN = 200005, MaxK = 18;

struct Edge {
	int to, a, b;
	Edge *next;
} edge[2 * MaxN], *head[MaxN], *top = edge;

inline void add_edge(int u, int v, int a, int b) {
	*++top = Edge{.to = v, .a = a, .b = b, .next = head[u]};
	head[u] = top;
}

int n, fa[MaxN][MaxK], dep[MaxN];
int cnt[MaxN];

void dfs(int u) {
	int *Fa = fa[u];
	for (int i = 1; i < MaxK; ++i) Fa[i] = fa[Fa[i - 1]][i - 1];
	for (Edge *e = head[u]; e; e = e->next) {
		int v = e->to;
		if (v == Fa[0]) continue;
		fa[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = MaxK; i--; ) {
		if (diff >> i & 1) u = fa[u][i];
	}
	if (u == v) return u;
	for (int i = MaxK; i--; ) {
		int uf = fa[u][i], vf = fa[v][i];
		if (uf != vf) u = uf, v = vf;
	}
	return fa[u][0];
}

void modify(int u, int v) {
	int w = lca(u, v);
	cnt[u] += 1;
	cnt[v] += 1;
	cnt[w] -= 2;
}

ll ans = 0;

void dfs2(int u) {
	for (Edge *e = head[u]; e; e = e->next) {
		int v = e->to;
		if (v == fa[u][0]) continue;
		dfs2(v);
		cnt[u] += cnt[v];
		ans += std::min((ll)cnt[v] * e->a, (ll)e->b);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, a, b;
		scanf("%d%d%d%d", &u, &v, &a, &b);
		add_edge(u, v, a, b);
		add_edge(v, u, a, b);
	}
	dfs(1);
	for (int i = 1; i < n; ++i) {
		modify(i, i + 1);
	}
	dfs2(1);
	printf("%lld\n", ans);
	return 0;
}