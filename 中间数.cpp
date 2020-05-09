#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		int numx=0;
		int numd=0;
		for(int j=1;j<=n;j++){
			if(a[j]>a[i])numd++;
			if(a[j]<a[i])numx++;
		}
		if(numx==numd){
			cout<<a[i]<<endl;
			flag=1;
			break;
		}
	}
	if(!flag)cout<<-1<<endl;
	return 0;
} 
