#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> op;
priority_queue<int, vector<int>, greater<int>> kk;
int main()
{
    int n, qqq, k, gg, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> qqq;
        kk.push(qqq);
    }
    for (int i = 1; i < n; i++)
    {
        int sb, tx;
        sb = kk.top();
        kk.pop();
        tx == kk.top();
        kk.pop();
        gg = abs(sb - tx);
        op.push(gg);
    }
    while (k != 0)
    {
        ans +=op.top();
        op.pop();
        k--;
    }
    cout<<ans;
}