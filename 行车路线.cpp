#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=505;
const int inf=0x3f3f3f3f;
ll x[MAX_N][MAX_N],d[MAX_N][MAX_N];
ll xdis[MAX_N],ddis[MAX_N];
bool vis[MAX_N];
int cnt[MAX_N];
int que[MAX_N];
int n,m;
void floyd(){
	for(int k=1;k<n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(k==i||j==k)continue;
				if(x[i][j]>x[i][k]+x[k][j]){
					x[i][j]=x[i][k]+x[k][j];
				}
			}
		}
	}
}
bool spfa(int start,int n){
	int front=0,rear=0;
    for(int v=1;v<=n;v++)
    {
        if(v==start)
        {
            que[rear++]=v;
            vis[v]=true;
            cnt[v]=1;
            xdis[v]=0;
            ddis[v]=0;
        }
        else
        {
            vis[v]=false;
            cnt[v]=0;
            xdis[v]=inf;
            ddis[v]=inf;
        }
    }
	while(front!=rear)
    {
        int y=que[front++];
        vis[y]=false;
        if(front>=MAX_N)front=0;
        for(int i=1;i<=n;i++){
			if(i==y)continue;
			if(ddis[i]>ddis[y]+d[y][i]){
			   ddis[i]=ddis[y]+d[y][i];
			   if(!vis[i])
                {
                    vis[i]=true;
                    que[rear++]=i;
                    if(rear>=MAX_N-1)rear=0;
                    if(++cnt[i]>n)return false; 
                }
			}
			if(ddis[i]>xdis[y]+d[y][i]){
			   ddis[i]=xdis[y]+d[y][i];
		       if(!vis[i])
                {
                    vis[i]=true;
                    que[rear++]=i;
                    if(rear>=MAX_N)rear=0;
                    if(++cnt[i]>n)return false; 
                }
			}
			if(x[y][i]<inf){
				ll temp=x[y][i]*x[y][i];
			    if(xdis[i]>ddis[y]+temp){
			 	  xdis[i]=ddis[y]+temp;
				  if(!vis[i])
                  {
                    vis[i]=true;
                    que[rear++]=i;
                    if(rear>=MAX_N)rear=0;
                    if(++cnt[i]>n)return false; 
                   }
			    }   
			}
	    }	
    }
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				x[i][j]=d[i][j]=0;
				continue;
			}
			x[i][j]=x[i][j]=inf;
			d[i][j]=d[i][j]=inf;
		}
	}
	
	for(int i=1;i<=m;i++){
		int t,a,b;
		ll c;
		cin>>t>>a>>b>>c;
		if(t==1){
			x[a][b]=x[b][a]=min(x[a][b],c);
		}
		if(t==0)d[a][b]=d[b][a]=min(d[a][b],c);	   	
	}
	for(int i=1;i<=501;i++){
		xdis[i]=ddis[i]=inf;
	} 
	floyd();
	spfa(1,n);
	cout<<min(xdis[n],ddis[n])<<endl;
	return 0;
}
