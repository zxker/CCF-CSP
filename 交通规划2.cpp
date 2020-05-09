#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10005;
const int MAX_m=100005;
struct node{
    int next,len;
    node(int a,int b){
    	next=a;
    	len=b;
	}
}; 
struct po{
	int x,dist;
	po(int xx,int dd){
		x=xx;
		dist=dd;
	}
	bool operator<(const po&A)const{
	   return dist>A.dist;
	}
};
vector<node>ve[MAX_N];
int dist[MAX_N],cost[MAX_N];
bool vst[MAX_N];
int n,m;
void djs(){
	priority_queue<po>q;
	memset(dist,0x3f,sizeof(dist));
	memset(vst,false,sizeof(vst));
	memset(cost,0,sizeof(cost));
	q.push(po(1,0));
	dist[1]=0;
	while(!q.empty()){
		int v=q.top().x;
		q.pop();
		if(vst[v])continue;
		vst[v]=true;
	    for(int i=0;i<ve[v].size();i++){
	    	int x=ve[v][i].next;
	    	if(vst[x])continue;
	    	if(dist[v]+ve[v][i].len<dist[x]){
	    		dist[x]=dist[v]+ve[v][i].len;
	    		cost[x]=ve[v][i].len;
	    		q.push(po(x,dist[x]));
			}else if(dist[v]+ve[v][i].len==dist[x]){
				cost[x]=min(cost[x],ve[v][i].len);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
   		int ip1,ip2,ip3;
   		cin>>ip1>>ip2>>ip3;
   		ve[ip1].push_back(node(ip2,ip3));
   		ve[ip2].push_back(node(ip1,ip3));
	}
    djs();
    int ans=0;
    for(int i=1;i<=n;i++){
    	ans+=cost[i];
	}
	cout<<ans<<endl;
	return 0;
}
