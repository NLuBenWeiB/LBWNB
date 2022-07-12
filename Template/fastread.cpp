#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
int read(){
    ll x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if(c=='-')
        f=-1;
        c=getchar();
    } 
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int main(){
    ll a[10000];
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    a[i]=read();
}
