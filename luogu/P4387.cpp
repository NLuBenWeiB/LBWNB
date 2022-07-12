#include <bits/stdc++.h>
using namespace std;
stack<int> op;
int a[100005], b[100005];
int main()
{
    int q, n,sum;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> n;
        sum=1;
        for (int yy = 1; yy <= n; yy++)
            cin >> a[yy];
        for (int yy = 1; yy <= n; yy++)
            cin >> b[yy];
        for (int yy = 1; yy <= n; yy++)
        {
            op.push(a[yy]);
            while (op.top() == b[sum])
            {
             op.pop();
             sum++;
             if(op.empty())
             break;
            }
        }
        if(op.empty())
        cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
            while(!op.empty())
            op.pop();
        }
    }
}