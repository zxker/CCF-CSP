#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1005;
ll ans[MAX_N][MAX_N];
int cg[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
bool vst[MAX_N][MAX_N],a[MAX_N][MAX_N];
struct po{
	int x,y;
	ll num;
	po(int xx,int yy,ll ff){
		x=xx;
		y=yy;
		num=ff;
	}
};
int n,m,k,d;
vector<po>ve;
queue<po>q;
void bfs(){
	while(!q.empty()){
		po now=q.front();
		q.pop();
		for(int i=0;i<=3;i++){
			int xx=now.x+cg[i][0];
			int yy=now.y+cg[i][1];
			ll ff=now.num;
			if(yy<1||yy>n||xx<1||xx>n||vst[xx][yy]||a[xx][yy])continue;
			vst[xx][yy]=1;
			ans[xx][yy]=ff+1;
			q.push(po(xx,yy,ff+1));
		}
	}
}
int main(){
	cin>>n>>m>>k>>d; 
	for(int i=1;i<=m;i++){
        int x,y;
		cin>>x>>y;
		q.push(po(x,y,0));
		vst[x][y]=true;	
	}
	for(int i=1;i<=k;i++){
		int x,y;
		ll num;
		cin>>x>>y>>num;
		ve.push_back(po(x,y,num));
	}
	for(int i=1;i<=d;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	bfs();
	ll s=0;
	for(auto it:ve){
		s+=ans[it.x][it.y]*it.num;
	}
	cout<<s<<endl;
	return 0;
}
