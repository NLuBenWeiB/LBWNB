#include <bits/stdc++.h>
using namespace std;
int n, m, gpp, ecs[10005], sd, jl, timen = 1;
bool used[10005];
map<int, int> l, dsb;
vector<int> a[10005];
int main()
{

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        printf("? %d %d\n", 1, i);
        fflush(stdout);
        scanf("%d", &gpp);
        a[gpp].push_back(i);
        l[i] = gpp;
    }
    ecs[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        timen = 1;
        sd = l[i] + 1;
        for (int ok = 0; ok < a[sd].size(); ok++)
        {
            if (used[a[sd][ok]] != 1){
            printf("? %d %d\n", i, a[sd][ok]);
            fflush(stdout);
            scanf("%d", &jl);    
            }
            else continue;   
            if (jl == 1)
            {
                if (timen == 1)
                {
                    ecs[i * 2] = a[sd][ok];
                    used[a[sd][ok]]=1;
                    dsb[a[sd][ok]] = i * 2;
                    timen++;
                }
                else if (timen == 2)
                {
                    ecs[i * 2 + 1] = a[sd][ok];
                    used[a[sd][ok]]=1;
                    dsb[a[sd][ok]] = i * 2 + 1;
                    break;
                }
            }
        }
    }
    cout << "! ";
    for (int i = 2; i <= n; i++)
    {
        if (dsb[i] % 2 == 0)
            cout << dsb[i] / 2 << " ";
        else if (dsb[i] % 2 == 1)
            cout << (dsb[i] - 1) / 2 << " ";
    }
}