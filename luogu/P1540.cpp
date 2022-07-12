#include <bits/stdc++.h>
using namespace std;
queue<int> op;
bool a[1005];
int main(){
    int n,m,dc,ans=0;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>dc;
        if(op.size()!=m&&a[dc]!=1){
        a[dc]=1;
        ans++;
        op.push(dc);
        }
        else if(a[dc]!=1){
            a[op.front()]=0;
            op.push(dc);
            op.pop();
            ans++;
            a[dc]=1;
        }
        else if(a[dc]==1){
            continue;
        }
    }
    cout<<ans;
}