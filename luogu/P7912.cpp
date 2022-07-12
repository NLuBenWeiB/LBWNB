#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
ll fuck,qq=1,g=0,a[200005];
queue<int> op;
inline ll read(){
    ll x=0,f=1;
    char c;
    c=getchar();
    while (c<'0'||c>'9')
    {
        if(c=='-')
        f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-30;
        c=getchar();
    }
    return x*f;
}
void write(ll x) {
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
     printf(" ");
}
int main() {
    ll n,now,now1=0;
    cin>>n;
    g=n;
    a[0]=-1;
    for(ll i=1; i<=n; i++){
    	a[i]=read();
        op.push(i);
	}
    while(!op.empty()){
    now=op.front();
    if(a[now]!=a[now1])
    write(now);
    else now1=now;
    op.pop();
    }
}