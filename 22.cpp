#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const ll maxn=100005;
ll a[maxn],lazy[maxn*2],ans[maxn*2],m,n;
inline ll ls(ll p) {
	return p*2;
}
inline ll rs(ll p) {
	return p*2+1;
}
inline void push_up(ll p) {
	ans[p]=ans[ls(p)]+ans[rs(p)];
}
inline void build(ll l,ll r,ll p) {
	if(l==r) {
		ans[p]=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,ls(p));
	build(mid+1,r,rs(p));
	push_up(p);
}
inline void f(ll l,ll r,ll p,ll k) {
	lazy[p]+=k;
	ans[p]+=k*(r-l + 1);
}
inline void push_down(ll l,ll r,ll p) {
	ll mid=(l+r)/2;
	f(l,mid,ls(p),lazy[p]);
	f(mid+1,r,rs(p),lazy[p]);
	lazy[p]=0;
}
inline void up_date(ll nl,ll nr,ll l,ll r,ll p,ll k) {
	if(nl>=l&&nr<=r) {
		ans[p]+=k*(r-l+1);
		return;
	}
	ll mid=(l+r)/2;
	push_down(nl,nr,p);
	if(nr<=mid) up_date(nl,nr,l,mid,p,k);
	if(nr>mid) up_date(nl,nr,mid+1,r,p,k);
	push_up(p);
}
inline ll findn(ll nl,ll nr,ll l,ll r,ll p) {
	if (nl > r || l > nr )return 0;
	if(nl>=l&&r>=nr)
		return ans[p];
	ll mid=(r+l)/2;
	return findn(nl,nr,l,mid,ls(p))+findn(nl,nr,mid+1,r,rs(p));
}
int main() {
	freopen("in.in", "r", stdin);
	ll cz,er,b,c,d,e;
	scanf("%lld%lld",&n,&m);
	for(ll i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	for(int i=1; i<=m; i++) {
		scanf("%lld",&cz);
		if(cz==1) {
			scanf("%lld%lld%lld",&er,&b,&c);
			up_date(er,b,1,n,1,c);
		}
		if(cz==2) {
			scanf("%lld%lld%",&d,&e);
			printf("%lld\n",findn(d,e,1,n,1));
		}
	}
}