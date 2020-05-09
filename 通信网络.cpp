#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+5;
const int MAX_M=10000+5;
struct edge{
    int v,next;
}E[MAX_M];
int p[MAX_N],eid;
int result[MAX_N][MAX_N];
void init(){
    memset(p,-1,sizeof(p));
    eid=0;
}
void insert(int u,int v){
    E[eid].v=v;
    E[eid].next=p[u];
    p[u]=eid++;
}
int vst[MAX_N];
void dfs(int star,int u){
	result[star][u]=result[u][star]=1;
	vst[u]=1;
    for(int i=p[u];i+1;i=E[i].next){
        if(!vst[E[i].v]){
            dfs(star,E[i].v);
        }
    }
}
int main(){
	int n,m;
	cin>>n>>m;
	init();
	while(m--){
		int ip1,ip2;
		cin>>ip1>>ip2;
		insert(ip1,ip2);
	}
    for(int i=1;i<=n;i++){
    	memset(vst,0,sizeof(vst));
    	dfs(i,i);
	}	
	int ans=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(result[i][j]==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
