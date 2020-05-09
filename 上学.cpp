#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	int r,g,y;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int k,t;
		cin>>k>>t;
		if(k==0)sum+=t;
		else if(k==1){
			sum+=t;
		}
		else if(k==2){
			sum+=t+r;
		}
		else ;
	}
	cout<<sum<<endl;
	return 0;
} 
