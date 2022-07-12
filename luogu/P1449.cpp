#include <bits/stdc++.h>
using namespace std;
int a, n, g = 1;
char b[1005];
stack<int> op;
int main()
{
    int i=0;
    while (1)
    {
        cin>>b[i];
        if(b[i]=='@')
        break;
        i++;
    }
    n = strlen(b);
    n--;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != '.' && b[i] != '*' && b[i] != '-' && b[i] != '+' && b[i] != '/')
        {
            a = a * 10 + b[i] - '0';
        }
        else if (b[i] == '.')
        {
            op.push(a);
            a = 0;
            continue;
        }
        if (b[i] == '-')
        {
            int kk, jj;
            kk = op.top();
            op.pop();
            jj = op.top();
            op.pop();
            jj -= kk;
            op.push(jj);
        }
        if (b[i] == '*')
        {
            int kk, jj;
            kk = op.top();
            op.pop();
            jj = op.top();
            op.pop();
            kk *= jj;
            op.push(kk);
        }
        if (b[i] == '+')
        {
            int kk, jj;
            kk = op.top();
            op.pop();
            jj = op.top();
            op.pop();
            kk += jj;
            op.push(kk);
        }
        if (b[i] == '/')
        {
            int kk, jj;
            kk = op.top();
            op.pop();
            jj = op.top();
            op.pop();
            jj /= kk;
            op.push(jj);
        }
    }
    cout << op.top();
}