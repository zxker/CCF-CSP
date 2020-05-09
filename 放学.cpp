#include<iostream>
#include<cstring>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
int nextlight(int x){
	if(x==1)return 3;
	if(x==3)return 2;
	if(x==2)return 1;
}
ll mp[5]; 
int main(){
    ll r,y,g;
	cin>>mp[1]>>mp[2]>>mp[3];
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		 int k;
		 ll t;
      	 cin>>k>>t;	 
 	     int now=k;//µÆ×´Ì¬ 
 	     if(k==0){
 	     	sum+=t;
 	     	continue;
		}
 	     ll timesum=sum;
 	     timesum%=2*(mp[1]+mp[2]+mp[3]);
		 if(timesum>=t){
		 	timesum-=t;
		 	now=nextlight(now);
		     while(timesum>mp[now]){
		     	timesum-=mp[now];
		     	now=nextlight(now);
			 }
			 if(now==1)sum+=mp[1]-timesum;
	         if(now==2)sum+=mp[1]+mp[2]-timesum;
	         continue;
		 }else{
		     t-=timesum;
	         if(now==1)sum+=t;
	         if(now==2)sum+=mp[1]+t;
		}
	}
	cout<<sum<<endl; 
	return 0;
} 
