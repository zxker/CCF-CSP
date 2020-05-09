#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int a,b,len;
	bool operator<(const node&A)const{
		return len<A.len;
	}
}E[200005];
int fa[100005];
int n,m; 
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]);
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		cin>>E[i].a>>E[i].b>>E[i].len;
	}
	sort(E+1,E+m+1);
	for(int i=1;i<=m;i++){
		int ip1=E[i].a;
		int ip2=E[i].b;
		ip1=findfa(ip1);
		ip2=findfa(ip2);
		if(ip1!=ip2){
		    fa[ip1]=ip2;
		}
		if(findfa(1)==findfa(n)){
			cout<<E[i].len<<endl;
			break;
		}
	}
	return 0;
}
