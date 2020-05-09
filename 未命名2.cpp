#include<bits/stdc++.h>
using namespace std;
int a[20][20],temp[20][20];
int b[6][6];
int t;
bool vst[20][20];
struct po{
	int x;int y;
	po(int xx,int yy){
		x=xx;
		y=yy;
	}
};
vector<po>ve;
bool judge(){
	for(int i=1;i<=4;i++){
		if(a[ve[i].x+1][ve[i].y]==1||ve[i].x+1>15){
			return false;
		}
	}
	return true;
}
int main(){
	ve.push_back(po(0,0));
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>b[i][j];
		}
	}
	cin>>t;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(b[i][j]==1){
				ve.push_back(po(i,j+t-1));
			}
		}
	}
	int flag=0;
	while(true){
		if(judge()){
			for(int i=1;i<=4;i++){
				ve[i].x++;
			}
		}else{
			flag=1;
			for(int i=1;i<=4;i++){
				a[ve[i].x][ve[i].y]=1;
			}
		}
		if(flag)break;
	}
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++){
			if(j==1)cout<<a[i][j];
			else cout<<" "<<a[i][j];
		}
		cout<<endl;
	}	
	return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
0 1 1 0 
0 0 1 1
0 0 0 0
3
*/ 
