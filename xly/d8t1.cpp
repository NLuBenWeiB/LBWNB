#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
long long ol[50005] = {};
bool used[50005] = {};
inline int gcd(register int a, register int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    register long long t, n, ans;
    scanf("%d",&t);
    for (register int i = 1; i <= t; i++) {
        ans = 0;
        scanf("%d",&n);
        for (register int u = 1; u <= n; u++)
            for (register int op = u+1; op <= n; op++) {
                register int ll = gcd(u, op);
                for (register int wwe = 1; wwe <= ll; wwe++)
                    if (gcd(ll, wwe) <= 1)
                        ans++;
            }
        ans*=2;
        for (register int u = 1; u <= n; u++)
        {
            for (register int wwe = 1; wwe <= u; wwe++)
                if (gcd(u, wwe) <= 1)
                    ans++;
        }
        cout << ans % 1000000007 << endl;
    }
}