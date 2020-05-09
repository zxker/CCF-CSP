#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1+1;i<=x2;i++){
			for(int j=y1+1;j<=y2;j++){
				if(a[i][j])continue;
				if(a[i][j]==0){
					a[i][j]=1;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
