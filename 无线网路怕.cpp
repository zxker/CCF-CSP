#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct po{
	ll x,y;
	int pos;
	int feet=0;
	int knum=0;
	po(ll xx,ll yy,int p){
		x=xx;
		y=yy;
		pos=p;
	}
};
vector<po>ve;
bool vst[105];
int n,m,k,r;
bool judge(po a,po b){
	ll re;
	re=((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
	if(re<=(ll)r*r)return true;
	return false;
}
void bfs(){
	queue<po>q;
	memset(vst,0,sizeof(vst));
	vst[1]=true;
	q.push(ve[1]);
	while(!q.empty()){
		po now=q.front();
		q.pop();
		if(now.pos==2){
			cout<<now.feet-1<<endl;
			break;
		}
		for(int i=1;i<ve.size();i++){
			if(vst[i])continue;
			if(now.knum==k&&i>n)continue;
			if(!judge(now,ve[i]))continue;
			if(i>n)ve[i].knum=now.knum+1;
			else ve[i].knum=now.knum;
			ve[i].feet=now.feet+1;
			vst[i]=true;
			q.push(ve[i]);
		}
	}
}
int main(){
	cin>>n>>m>>k>>r;
	ve.push_back(po(0,0,0));
	for(int i=1;i<=n;i++){
		ll ip1,ip2;
		cin>>ip1>>ip2;
	    ve.push_back(po(ip1,ip2,i)); 	
	}
	for(int i=1;i<=m;i++){
		ll ip1,ip2;
		cin>>ip1>>ip2;
		ve.push_back(po(ip1,ip2,n+i));
	}
	bfs();
	return 0;
}
