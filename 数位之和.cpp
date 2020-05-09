#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int ans=0;
	while(n){
		ans+=n%10;
		n=n/10;
	}
	cout<<ans<<endl; 
	return 0;
}
