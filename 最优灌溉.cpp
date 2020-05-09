#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1010;
struct po{
	int a,b;
	ll len;
	bool operator<(const po&A)const{
		return len<A.len;
	}
}E[100010];
int fa[MAX_N],n,m;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int findx(int x){
	if(x==fa[x])return x;
	return fa[x]=findx(fa[x]);
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		cin>>E[i].a>>E[i].b>>E[i].len; 
	} 
	sort(E+1,E+1+m);
	int num=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int x=E[i].a;
		int y=E[i].b;
		x=findx(x);
		y=findx(y);
		//cout<<x<<" "<<y<<endl;
		if(x!=y){
			fa[x]=y;
			num++;
			ans+=E[i].len;
		}
		if(num==n-1)break;
	}
	cout<<ans<<endl;
	return 0;
} 
