#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1005;
int h[MAX_N];
#include <random>
#include <iostream>
#include <ctime>
int main(){
	int n;
	srand(time(0));	
	n=rand()%10;
	ofstream in("F:\\a.txt",ios::app);
	in<<n<<endl;
	for(int i=1;i<=n;i++){
		int ip;
		//cin>>ip;
		ip=rand()%20;
		in<<ip<<" ";
		h[ip]++;
		if(i==1)cout<<h[ip];
		else cout<<" "<<h[ip];
	}
	cout<<endl;
	return 0;
}
