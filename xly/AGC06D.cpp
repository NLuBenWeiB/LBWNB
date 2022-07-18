#include <iostream>
#include <queue>
using namespace std;
queue<int> op;
int main()
{
    int a[100005], n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        op.push(a[i]);
    }
    int g = op.front();
    op.pop();
    int gg = op.front();
    op.pop();
    while (1)
    {
        if(op.size()==1){
        cout<<op.front(); 
        return 0;   
        }
        int ggg=op.front();
        op.push(max(min(g,gg),min(gg,ggg)));
    }
}