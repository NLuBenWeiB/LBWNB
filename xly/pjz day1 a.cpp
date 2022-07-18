#include <bits/stdc++.h>
using namespace std;
char a[500005];
queue<int> lll;
int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    cin >> a;
    int n, yj = 0,fuck, yj1 = 0, op, i = 1;
    bool ji = 0, gg = 0;
    if (a[0] != '|')
    {
        cout << "error";
        return 0;
    }
    n = strlen(a);
    while (i < n)
    {
        if (i == 2&&fuck!=1)
        {
            yj = yj1;
        }
        else if (yj != yj1&&fuck!=1)
        {
        cout<<-1<<endl;
        fuck=1;
        }
        if (a[i] == '|')
        {
            gg=0;
            ji=0;
            if(i+1<n)
            if (a[i + 1] == '-' || a[i + 1] == '.')
            {
                cout << "error";
                return 0;
            }
            i++;
        }
        if ('0' <= a[i] && a[i] <= '9')
        {
            op = a[i] - '0';
            lll.push(op);
            i++;
        }
        if (a[i] == '-')
        {
            if (gg == 1)
            {
                yj1 += 2;
                lll.push(op);
                lll.push(op);
                gg = 0;
            }
            else
            {
                yj1++;
                lll.push(op);
                gg = 1;
            }
            ji = 1;
            i++;
        }
        if (a[i] == '.')
        {
            if (ji == 1)
            {
                lll.push(op);
                yj1++;
                ji = 0;
            }
            else if (ji == 0)
            {
                cout << "error";
                return 0;
            }
            i++;
        }
    }
    if(fuck!=1)
    cout<<yj<<endl;
    while(!lll.empty()){
        if(lll.empty())
        break;
        int now=lll.front();
        cout<<now;
        lll.pop();
    }
}