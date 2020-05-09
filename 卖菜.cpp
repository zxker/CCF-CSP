#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000;
int a[maxn+5];
int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
    for(int i=1;i<=N;i++){
    	if(i==1){
    		cout<<(a[1]+a[2])/2;
		}
		else if(i==N){
			cout<<" "<<(a[N]+a[N-1])/2;
		}else{
			cout<<" "<<(a[i-1]+a[i]+a[i+1])/3;
		}
	}
	cout<<endl;
	return 0;
}
