#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int sum=0;
	int fivesum=n/50;
	n-=fivesum*50;
	sum+=fivesum*7;
	int threesum=n/30;
	n-=threesum*30;
	sum+=threesum*4;
	int onesum=n/10;
	sum+=onesum;
	cout<<sum<<endl; 
	return 0;
} 
