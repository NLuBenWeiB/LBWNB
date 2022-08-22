#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int solve(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b) return min(5, a + 1);
	return max(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", solve(a, b));
	}
	return 0;
}
