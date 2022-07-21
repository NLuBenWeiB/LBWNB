#include <bits/stdc++.h>
using namespace std;
priority_queue<double, vector<double>, less<double>> q[5];
int main()
{
    double ans = 0;
    int a, b, c, d, kl;
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= a; i++)
    {
        cin >> kl;
        q[1].push(kl);
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> kl;
        q[2].push(kl);
    }
    for (int i = 1; i <= c; i++)
    {
        cin >> kl;
        q[3].push(kl);
    }
    for (int i = 1; i <= d; i++)
    {
        cin >> kl;
        q[4].push(kl);
    }
    int w,d1,m1,f1;
    cin >> w;
    for (int i = 1; i <= w; i++)
    {
        ans=0;
        cin>>d1>>m1>>f1;
        ans += q[1].top();
        q[1].pop();
        for(int b=1;b<=d1;b++){
        ans+=q[2].top();    
        q[2].pop();
        }
        for(int b=1;b<=m1;b++){
        ans+=q[3].top();    
        q[3].pop();
        }
        for(int b=1;b<=f1;b++){
        ans+=q[4].top();    
        q[4].pop();
        }
        printf("%.2lf\n",ans/11);
    }
}
