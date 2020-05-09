#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	int flag=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=flag){
			ans++;
			flag=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
