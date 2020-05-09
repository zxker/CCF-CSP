#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
struct Node{
	int a;
	int b;
	int t;
	bool operator<(const Node &A)const{
		return t<A.t;
	}
}node[maxn+5];
int fa[maxn+5];
int n,m,root;
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int ffind(int x){
	if(x==fa[x])return x;
	return fa[x]=ffind(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d",&root);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].t);		
	}
	sort(node+1,node+1+m);
	int cur=0;
	for(int i=1;i<=m;i++){ 
	    int x=node[i].a;
	    int y=node[i].b;
	    x=ffind(x);
	    y=ffind(y);
	    if(x!=y){
	    	cur++;
	    	fa[x]=y;
	    	if(cur==n-1){
	    		cout<<node[i].t;
	    		break;
			}
		}
	}
	return 0;
}
