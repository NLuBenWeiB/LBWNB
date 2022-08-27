#include<iostream>
#include<cstdio>
using namespace std;

const int N=200005;
typedef long long ll;

int n,q;

struct ee{
	int v;int nxt;
}e[N];
int h[N],et=0;
inline void add(int U,int V){
	e[++et]=(ee){V,h[U]};
	h[U]=et;
}

ll tr[N<<2];
inline ll lwbt(int X){
	return X&(-X);
}
inline void Tadd(int X,ll W){
	while(X<=(n<<1)){
		tr[X]+=W;
		X+=lwbt(X);
	} 
}
inline ll Tqry(int X){
	ll ANS=0;
	while(X){
		ANS+=tr[X];
		X-=lwbt(X);
	}
	return ANS;
}

int euler[N<<1],len=0,bg[N],ed[N];

inline void dfs(int X){
	euler[++len]=X;bg[X]=len;
	for(int i=h[X];i;i=e[i].nxt){
		dfs(e[i].v);
	}
	euler[++len]=X;ed[X]=len;
}

int main(){
	scanf("%d%d",&n,&q);
	int fa;
	for(int i=2;i<=n;++i){
		scanf("%d",&fa);
		add(fa,i);
	}
	dfs(1);
	int op,x;ll w;
	for(int i=1;i<=q;++i){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%lld",&x,&w);
			Tadd(bg[x],w);
		}else{
			scanf("%d",&x);
			printf("%lld\n",Tqry(ed[x])-Tqry(bg[x]-1));
		}
	}
}
