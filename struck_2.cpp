#include<bits/stdc++.h>
using namespace std;
const int MAX_N=50;
char ch[MAX_N][MAX_N];
int n,m,cg[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int bx,by,ex,ey;
bool vst1[MAX_N][MAX_N],vst2[MAX_N][MAX_N],vst[MAX_N][MAX_N];
bool hh[MAX_N][MAX_N][MAX_N][MAX_N];
void dfs(int x1,int y1){  
	 if(ch[x1][y1]=='S'||ch[x1][y1]=='T'||ch[x1][y1]=='+'){
	 	 for(int i=0;i<=3;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	hh[x1][y1][xx][yy]=true;
	 	 	if(vst[xx][yy])continue;
	 	 	vst[xx][yy]=true;
	 	 	vst1[xx][yy]=true; 
	 	 	dfs(xx,yy);
		  }
	 }
	 if(ch[x1][y1]=='-'){
	 	for(int i=2;i<=3;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	    if(ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	hh[x1][y1][xx][yy]=true;
	 	 	if(vst[xx][yy])continue;
	 	 	vst1[xx][yy]=true; 
	 	 	vst[xx][yy]=true;
	 	 	dfs(xx,yy);
		  }
	 }
	 if(ch[x1][y1]=='|'){
	 	for(int i=0;i<=1;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	hh[x1][y1][xx][yy]=true;
	 	 	if(vst[xx][yy])continue;
	 	 	vst[xx][yy]=true;
	 	 	vst1[xx][yy]=true;
	 	 	dfs(xx,yy);
		  }
	 }
	 if(ch[x1][y1]=='.'){
	 	for(int i=0;i<=0;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	hh[x1][y1][xx][yy]=true;
	 	 	if(vst[xx][yy])continue;
	 	 	vst[xx][yy]=true;
	 	 	vst1[xx][yy]=true; 
	 	 	dfs(xx,yy);
		  }
	 }
}
void dfs2(int x,int y){
	for(int i=0;i<=3;i++){
		int xx=x+cg[i][0];
	 	int yy=y+cg[i][1];
	 	if(vst[xx][yy]||ch[xx][yy]=='#'||hh[xx][yy][x][y]==false)continue;
	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	vst[xx][yy]=true;
	 	vst2[xx][yy]=true;; 
	 	dfs2(xx,yy);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
			if(ch[i][j]=='S'){
				bx=i;
				by=j;
			}
			if(ch[i][j]=='T'){
				ex=i;
				ey=j;
			}
		}
	}
	vst[bx][by]=1;
	dfs(bx,by);
	vst1[bx][by]=true;
	if(vst1[ex][ey]==false){
		cout<<"I'm stuck!"<<endl;
		return 0;
	}
	memset(vst,0,sizeof(vst));
	vst[ex][ey]=1;
	vst2[ex][ey]=true;
	dfs2(ex,ey);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vst1[i][j]&&!vst2[i][j]){
				ans++;
			}
		}
	} 
	cout<<ans<<endl;
	return 0;
}
