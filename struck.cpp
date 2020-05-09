#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=50;
char ch[MAX_N][MAX_N];
int cg[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vst[MAX_N][MAX_N];
int n,m;
int bx,by,ex,ey;
int zxk=0;
void dfs(int x1,int y1,int x2,int y2){
    
	 if(ch[x1][y1]=='S'||ch[x1][y1]=='T'||ch[x1][y1]=='+'){
	 	 for(int i=0;i<=3;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(vst[xx][yy]||ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	vst[xx][yy]=true;
	 	 	dfs(xx,yy,x2,y2);
		  }
	 }
	 if(ch[x1][y1]=='-'){
	 	for(int i=0;i<=1;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(vst[xx][yy]||ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	vst[xx][yy]=true;
		  }
	 }
	 if(ch[x1][y1]=='|'){
	 	for(int i=2;i<=3;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(vst[xx][yy]||ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	vst[xx][yy]=true;
	 	 	dfs(xx,yy,x2,y2);
		  }
	 }
	 if(ch[x1][y1]=='.'){
	 	for(int i=2;i<=2;i++){
	 	 	int xx=x1+cg[i][0];
	 	 	int yy=y1+cg[i][1];
	 	 	if(vst[xx][yy]||ch[xx][yy]=='#')continue;
	 	 	if(xx>n||xx<1||yy<1||yy>m)continue;
	 	 	vst[xx][yy]=true;
	 	 	dfs(xx,yy,x2,y2);
		  }
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
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			memset(vst,false,sizeof(vst));
			if(ch[i][j]=='S'||ch[i][j]=='T'||ch[i][j]=='#')continue;
			vst[bx][by]=true;
			zxk=0;
			dfs(bx,by,i,j);
			if(zxk){
				memset(vst,false,sizeof(vst));
				vst[i][j]=true;
				zxk=0;
				dfs(i,j,ex,ey);
			    if(!zxk){
			   	cout<<i<<" "<<j<<endl; 
			   }	
			}
		}
	}
	if(ans==0)cout<<"I'm stuck!"<<endl;
	else cout<<ans<<endl;
	return 0;
} 
