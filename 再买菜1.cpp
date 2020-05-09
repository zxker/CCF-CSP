#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300;
int a[maxn+5],b[maxn+5];
int n;
bool mark[maxn+5][maxn+5][maxn+5]; 
void dfs(int cur){
	if(cur==n+1){
		if(a[n]==(b[n]+b[n-1])/2){
	    for(int i=1;i<=n;i++){
	      if(i==1)cout<<b[i];
	      else cout<<" "<<b[i];
	    }
		     exit(0); 
		}
		return;
	}
	int t=3*a[cur-1]-b[cur-1]-b[cur-2];
	for(int i=t;i<t+3;i++){
		if(i<=0)continue;
		if(mark[cur][i][b[cur-1]]==true)continue;
		b[cur]=i;
		dfs(cur+1);
		mark[cur][i][b[cur-1]]=true;
	}
}
int main(){
	cin>>n;
	memset(mark,false,sizeof(true));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=2*a[1];i++){
		int t=2*a[1]-i;
		b[1]=i;
		for(int j=t;j<=t+1;j++){
			b[2]=j;
			dfs(3);
		}
	}

	cout<<endl;
	return 0;
}
