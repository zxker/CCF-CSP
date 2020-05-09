#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005];
int ans=1000008;
int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=min(abs(a[i]-a[j]),ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
