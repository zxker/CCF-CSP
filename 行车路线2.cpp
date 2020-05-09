#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=505;
ll x[MAX_N][MAX_N],d[MAX_N][MAX_N];
ll xd[MAX_N],dd[MAX_N];
int cnt[MAX_N];
int que[MAX_N],vis[MAX_N];
int n,m;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(k==i||k==j||i==j)continue;
				if(x[i][k]+x[k][j]<x[i][j]){
					x[i][j]=x[i][k]+x[k][j];
				}
			}
		}
	}
}
bool SPFA(int start,int nn) //源点,点个数
{
    int front=0,rear=0;
    for(int v=1;v<=nn;v++) //初始化
    {
        if(v==start)
        {
            que[rear++]=v;
            vis[v]=true;
            cnt[v]=1;
            xd[v]=0;
            dd[v]=0;
        }
        else
        {
            vis[v]=false;
            cnt[v]=0;
            xd[v]=0x3f3f3f3f;
            dd[v]=0x3f3f3f3f;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        vis[u]=false;
        if(front>=MAX_N)front=0; //循环队列 
        for(int i=1;i<=n;i++)
        {
            if(i==u)continue;
            if(xd[u]+d[u][i]<dd[i]){
            	dd[i]=xd[u]+d[u][i];
            	if(!vis[i]){
                  vis[i]=true;
                  que[rear++]=i;
                  if(rear>=MAX_N)rear=0; //循环队列 
                  if(++cnt[i]>nn)return false; //存在负环	
				}
			}
			if(dd[u]+d[u][i]<dd[i]){
				dd[i]=dd[u]+d[u][i];
				if(!vis[i]){
                  vis[i]=true;
                  que[rear++]=i;
                  if(rear>=MAX_N)rear=0; //循环队列 
                  if(++cnt[i]>nn)return false; //存在负环	
				}
			}
			if(dd[u]+x[u][i]*x[u][i]<xd[i]){
				xd[i]=dd[u]+x[u][i]*x[u][i];
				if(!vis[i]){
                  vis[i]=true;
                  que[rear++]=i;
                  if(rear>=MAX_N)rear=0; //循环队列 
                  if(++cnt[i]>nn)return false; //存在负环	
				}
			}
        }
    }
    return true;
}
int main(){
	cin>>n>>m;
	memset(x,0x3f,sizeof(x));
	memset(d,0x3f,sizeof(d));
    while(m--){
    	int t,a,b;
    	ll c;
    	cin>>t>>a>>b>>c;
        if(t){
        	x[a][b]=x[b][a]=min(c,x[a][b]);
		}else{
			d[a][b]=d[b][a]=min(c,d[a][b]);
		}	
	}
	floyd();
	SPFA(1,n);
	cout<<min(dd[n],xd[n])<<endl;
	return 0;
}

