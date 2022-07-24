#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull hx[100005], n, pds, power[100005], hxp[100005];
char ok[100005], pdsa[100005];
map<char, int> pp;
inline void csh()
{
    for (int i = 1; i <= 26; i++)
        pp['a' + i - 1] = i;
    power[0] = 1;
    for (int i = 1; i <= 63; i++)
        power[i] = power[i - 1] * 2;
}
int main()
{
    csh();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ok[i];
        hx[i] = hx[i - 1] * 2 + pp[ok[i]];
    }
    cin >> pds;
    for (int i = 1; i <= pds; i++)
    {
        cin >> pdsa[i];
        hxp[i] = hxp[i - 1] * 2 + pp[pdsa[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        if (ok[i] == pdsa[1])
        {
            ull hxz = hx[i + pds - 1] - hx[i - 1] * power[pds];
            cout << hxz << " " << hxp[pds] << " " << hx[i + pds - 1] << " " << hx[i - 1] * power[pds] << endl;
            if (hxz == hxp[pds])
            {
                cout << "True";
                return 0;
            }
        }
    }
    cout << "False";
}