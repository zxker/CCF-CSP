#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i]+a[j]==0)ans++;
		}
	}
	cout<<ans/2<<endl;
	return 0;
	
} 
