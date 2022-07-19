#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int main()
{
    int n, a[100005], f = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    if(a[i]<a[i+1])
    ans+=a[i+1]-a[i];
    cout<<ans+a[1];
}