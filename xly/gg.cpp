#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
struct edge
{
	int to, cap, rew;
};
struct d
{
	int A, B, C;
};
vector<edge> a[60005];
vector<d> xd, yd;
int dep[60005], iter[60005], ass, n1, n2, a1, b1, c1;
inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
inline void build(int n1, int n2)
{
	for (int i = 0; i < n1; i++)
		for (int b = 0; b < n2; b++)
		{
			ass = 0;
			if (gcd(xd[i].A, yd[b].A) == 1)
				ass++;
			if (gcd(xd[i].B, yd[b].B) == 1)
				ass++;
			if (ass > 1)
				continue;
			if (gcd(xd[i].C, yd[b].C) == 1)
				ass++;
			if (ass > 1)
				continue;
			if (ass <= 1)
			{
				a[i + 3].push_back((edge){b + n1 + 3, 1, a[b + n1 + 3].size()});
				a[b + n1 + 3].push_back((edge){i + 3, 0, a[i + 3].size() - 1});
			}
		}
}
inline void bfs(int s)
{
	for (int i = 1; i <= n1 + n2 + 2; i++)
		dep[i] = -1;
	queue<int> que;
	dep[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (int i = 0; i < a[now].size(); i++)
		{
			edge &e = a[now][i];
			if (e.cap > 0 && dep[e.to] < 0)
			{
				dep[e.to] = dep[now] + 1;
				que.push(e.to);
			}
		}
	}
}
inline int dfs(int s, int t, int f)
{
	if (s == t)
		return f;
	for (int &i = iter[s]; i < a[s].size(); i++)
	{
		edge &q = a[s][i];
		if (q.cap > 0 && dep[q.to] > dep[s])
		{
			int d = dfs(q.to, t, min(f, q.cap));
			if (d > 0)
			{
				q.cap -= d;
				a[q.to][q.rew].cap += d;
				return d;
			}
		}
	}
	return 0;
}
inline int maxdd(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		bfs(s);
		if (dep[t] < 0)
			return flow;
		for (int i = 1; i <= n1 + n2 + 2; i++)
			iter[i] = 0;
		int f;
		while ((f = dfs(s, t, 2147483647)) > 0)
		{
			flow += f;
		}
	}
}
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	n1 = read();
	n2 = read();
	for (int i = 3; i <= n1 + 2; i++)
	{
		a1 = read();
		b1 = read();
		c1 = read();
		xd.push_back((d){a1, b1, c1});
		a[1].push_back((edge){i, 1, a[i].size()});
		a[i].push_back((edge){1, 0, a[1].size() - 1});
	}
	for (int i = 3; i <= n2 + 2; i++)
	{
		a1 = read();
		b1 = read();
		c1 = read();
		yd.push_back((d){a1, b1, c1});
		a[i + n1].push_back((edge){2, 1, a[2].size()});
		a[2].push_back((edge){i + n1, 0, a[i + n1].size() - 1});
	}
	build(n1, n2);
	printf("%d", maxdd(1, 2));
}