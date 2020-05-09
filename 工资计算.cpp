#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int>mp;
int m[10];
void init(int x){
	if(x<=3500){
		mp[x]=x;
		return ;
	}
	int high=x-3500;
	int  ans;
	if(high<=1500){
		ans=x-high*3/100;
	}else if (high>1500&&high<=4500){
		ans=x-m[0]-(high-1500)*10/100;
	}
	else if(high>4500&high<=9000){
		ans=x-m[0]-m[1]-(high-4500)*20/100;
	}
	else if(high>9000&&high<=35000){
		ans=x-m[0]-m[1]-m[2]-(high-9000)*25/100;
	}
	else if(high>35000&&high<=55000){
		ans=x-m[0]-m[1]-m[2]-m[3]-(high-35000)*30/100;
	}
	else if(high>55000&&high<80000){
		ans=x-m[0]-m[1]-m[2]-m[3]-m[4]-(high-55000)*35/100;
	}
	else {
		ans=x-m[0]-m[1]-m[2]-m[3]-m[4]-m[5]-(high-80000)*45/100; 
	}
	mp[ans]=x;
	return;
}
int main(){
    int T;	
    cin>>T;
	m[0]=15*3;
	m[1]=(45-15)*10;
	m[2]=(90-45)*20;
	m[3]=(350-90)*25;
	m[4]=(550-350)*30;
	m[5]=(800-550)*35;
	for(int i=100;i<=100000;i+=100){
		init(i);
	}
	cout<<mp[T]<<endl;
	return 0;
}
