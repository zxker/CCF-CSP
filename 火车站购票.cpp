#include<bits/stdc++.h>
using namespace std;
int a[21][6];
void deal(int x){
	int flag=0;
	for(int i=1;i<=20;i++){
		int num=0;
		int flag1=0;
		for(int j=1;j<=5;j++){
		    if(a[i][j]&&flag1!=0)continue;
			if(a[i][j]==0){
				flag1=1;
				num++;
			}
			if(num==x){
				flag=1;
				for(int zz=j-x+1;zz<=j;zz++){
					a[i][zz]=1;
					cout<<(i-1)*5+zz<<" ";
				}
				break;
			}
			if(flag1&&a[i][j])break; 
		}
		if(flag==1){
	       break;		
		}
	}
	if(!flag){
		for(int i=1;i<=x;i++){
			deal(1);
		}
	}
}
int main(){
	int n;
	cin>>n; 
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		deal(num);
		cout<<endl;
	}
	return 0;
}
