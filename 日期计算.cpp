#include<bits/stdc++.h>
using namespace std;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isyear(int y,int m){
	if(y%400==0||(y%4==0&&y%100!=0)){
		if(m==2)return 29;
	}
	return mon[m];
}
int main(){
	int y,days;
	cin>>y>>days;
	int a1=1,a2=0;
	while(days--){
		if(a2>=isyear(y,a1)){
			a1++;
			a2=0;
		}
		a2++;	
	}
    cout<<a1<<endl;
	cout<<a2<<endl;
	return 0;
}
