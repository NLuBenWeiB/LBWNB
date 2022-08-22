#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
const int N=2005;
const int QM=1000005;
struct Point{
	int x;int y;int bx;int by;
};
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m,Q,sx,sy,qx[QM],qy[QM];
char ch[N][N];
bool ab[N][N],dab[N][N];
queue<Point> q;
int visx[N][N],visy[N][N];
inline bool slv(int nq){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			visx[i][j]=19260817;
			dab[i][j]=ab[i][j];
		}
	}
	for(int i=1;i<=nq;++i){
		dab[qx[i]][qy[i]]=0;
	}
	while(!q.empty()){
		q.pop();
	}
	q.push((Point){sx,sy,0,0});
	visx[sx][sy]=visy[sx][sy]=0;
	Point nw;
	while(!q.empty()){
		nw=q.front();q.pop();
		for(int i=0;i<4;++i){
			Point dnw=(Point){(nw.x+dx[i]+n)%n,(nw.y+dy[i]+m)%m,nw.bx+((nw.x+dx[i]<0)?-1:((nw.x+dx[i]>=n)?1:0)),nw.by+((nw.y+dy[i]<0)?-1:((nw.y+dy[i]>=m)?1:0))};
			if(!dab[dnw.x][dnw.y]){continue;}
			if(visx[dnw.x][dnw.y]==dnw.bx&&visy[dnw.x][dnw.y]==dnw.by){continue;}
			else{if(visx[dnw.x][dnw.y]==19260817){q.push(dnw);visx[dnw.x][dnw.y]=dnw.bx,visy[dnw.x][dnw.y]=dnw.by;continue;}else{return 1;}}
		}
	}
	return 0;
}
inline void init(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=0;i<n;++i){
		cin>>ch[i];
		for(int j=0;j<m;++j){
			if(ch[i][j]=='#'){
				ab[i][j]=0;
			}
			if(ch[i][j]=='.'){
				ab[i][j]=1;
			}
			if(ch[i][j]=='S'){
				ab[i][j]=1,sx=i,sy=j;
			}
		}
	}
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&qx[i],&qy[i]);
		--qx[i],--qy[i];
	}
	int L=0,R=Q,MID,ANS=-1;
	while(L<=R){
		MID=(L+R)>>1;
		if(slv(MID)){
			ANS=MID,L=MID+1;
		}else{
			R=MID-1;
		}
	}
	for(int i=0;i<=ANS;++i){
		puts("Yes");
	}
	for(int i=ANS+1;i<=Q;++i){
		puts("No");
	}
}

int main(){
	init();
	return 0;
}
