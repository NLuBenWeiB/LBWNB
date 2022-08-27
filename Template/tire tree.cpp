#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int id = 0, tire[500000][27], nd, jw[500000][27];
map<string, int> ok;
inline void inster(string dc)
{
    int len = dc.length();
    nd = 0;
    int now;
    for (int i = 0; i < len; i++)
    {
        now = dc[i] - 'a' + 1;
        if (tire[nd][now] == 0)
        {
            id++;
            tire[nd][now] = id;
            nd = id;
        }
        else if (tire[nd][now] != 0)
            nd = tire[nd][now];
        if (i == len - 1)
            jw[nd][now] = 1;
    }
}
inline bool findn(string dc)
{
    int len = dc.length();
    nd = 0;
    for (int i = 0; i < len; i++)
    {
        int now = dc[i] - 'a' + 1;
        if (tire[nd][now] == 0)
            return 0;
        else if (tire[nd][now] != 0)
                nd = tire[nd][now];
        if (nd!= 0 && i == len - 1 && jw[nd][now] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    string dc;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dc;
        inster(dc);
    }
    int cx;
    cin >> cx;
    for (int i = 1; i <= cx; i++)
    {
        cin >> dc;
        if (findn(dc))
        {
            if (ok[dc] == 1)
                cout << "REPEAT" << endl;
            else
            {
                ok[dc] = 1;
                cout << "OK" << endl;
            }
        }
        else
            cout << "WRONG" << endl;
    }
}