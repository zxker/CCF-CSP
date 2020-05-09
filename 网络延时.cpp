#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=20005;
int n,m;
int nodea,ans=0;
bool vst[MAX_N];
vector<int>ve[MAX_N];

void bfs1(){
	memset(vst,false,sizeof(vst));
	vst[1]=true;
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<ve[now].size();i++){
			int x=ve[now][i];
			if(vst[x])continue;
			nodea=x;
			vst[x]=true;
			q.push(x);
		}
	}
}
void bfs2(){
	memset(vst,false,sizeof(vst));
	queue<pair<int,int>>q;
	q.push(make_pair(nodea,0));
	vst[nodea]=true;
	while(!q.empty()){
		pair<int,int> now=q.front();
		q.pop();
		for(int i=0;i<ve[now.first].size();i++){
			int x=ve[now.first][i];
			if(vst[x])continue;
		    int feet=now.second+1;
		    vst[now.first]=1;
		    ans=feet; 
		    q.push(make_pair(x,feet));
		}	
	}
}
int main(){
	cin>>n>>m;
	for(int i=2;i<n+1;i++){
		int ip;
		cin>>ip;
		ve[ip].push_back(i);
		ve[i].push_back(ip);
	}
	for(int i=n+1;i<n+m+1;i++){
		int ip;
		cin>>ip;
		ve[ip].push_back(i);
		ve[i].push_back(ip);
	}
	bfs1();
	bfs2();
	cout<<ans<<endl;
    return 0 ;
}
