#include <bits/stdc++.h>
using namespace std;
int n1, n = 1, a[130];
map<int,int> op;
void ss(int n)
{
    if (n == 2)
    {
        cout << op[min(a[1], a[2])];
        return;
    }
    for (int i = 1; i < n; i += 2)
    {
        a[(i + 1) / 2] = max(a[i], a[i + 1]);
    }
    ss(n / 2);
}
int main()
{
    cin >> n1;
    for (int i = 1; i <= n1; i++)
        n *= 2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        op[a[i]]=i;
    }
    ss(n);
}