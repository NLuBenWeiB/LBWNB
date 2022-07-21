#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, l, r, a[100005], g;
    cin >> n >> m;
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= m; i += 2)
    {
        g = 0;
        for (int b = 1; b<=i; b += 2)
        {
            if (i % b == 0)
                g++;
        }
        if (g == 2)
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        if (l < 0 || r > m)
        {
            cout << "Crossing the line" << endl;
            continue;
        }
        cout<<a[r]-a[l]+1<<endl;
    }
}