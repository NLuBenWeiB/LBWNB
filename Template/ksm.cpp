#include <bits/stdc++.h>
using namespace std;
long long ksm(long long a, long long b, long long p)
{
    if (b == 0)
        return 1;
    long long res = ksm(a, b / 2, p);
    if (b % 2)
        return res * res % p * a % p;
    else
        return res * res % p;
}
int main()
{
    long n, m, p;
    cin >> n >> m >> p;
    cout <<n<<"^"<<m<<" mod "<<p<<"="<<ksm(n, m, p);
}