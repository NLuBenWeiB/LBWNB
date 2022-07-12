#include<bits/stdc++.h>
using namespace std;
int n,m,q,f[10010],c,d,a,b;
int fd(int x){
    if(f[x]==x)
    return x;
    else return f[x]=fd(f[x]);
}
void hb(int x,int y){
    f[fd(y)]=fd(x);
    return;
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>c>>d;
        hb(c,d);
    }
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        if(fd(a)==fd(b))
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}