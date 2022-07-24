#include <bits/stdc++.h>
using namespace std;
inline int gcd(register int a, register int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int t, l, r, x;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> l >> r >> x;
        l/=x;
        r/=x;
        if (l == r)
            cout << l << endl;
        else
            cout << 1 << endl;
    }
}