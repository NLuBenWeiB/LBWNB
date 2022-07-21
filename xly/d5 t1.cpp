#include <iostream>
using namespace std;
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n, x, tot = 1, ans = 0;
    scanf("%d", &n);
    int a[n + 10];
    scanf("%d", &a[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        while (a[tot] > x && tot >= 1) {
            if (a[tot] != a[tot - 1] && a[tot] != 0)
                ans++;
            tot--;
        }
        a[++tot] = x;
    }
    while (tot > 0) {
        if (a[tot] != a[tot - 1] && a[tot] != 0)
            ans++;
        tot--;
    }
    printf("%d", ans);
    return 0;
}