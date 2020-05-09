#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[105][105];
int cg[4][2]={
	{1,0},{-1,0},{0,1},{0,-1}
};
bool vst[105][105];
void deal2(int x1,int y1,int x2,int y2){
	   int xx1=x1;
	   int xx2=x2;
	   int yy1=y1;
	   int yy2=y2;
	   x1=n-1-y1;
	   y1=xx1;
	   x2=n-1-y2;
	   y2=xx2;//×ø±ê±ä»» 
	   char kk;
	   if(x1==x2){
	   	  kk='-';
	   	  int temp;
	   if(y1>y2){
		  int temp=y1;
		  y1=y2;
		  y2=temp;
	   } 
	   	  for(int i=y1;i<=y2;i++){
	   	      if(ch[x1][i]=='|')ch[x1][i]='+';
	   	      if(ch[x1][i]=='+')continue;
			  ch[x1][i]=kk;	
		  }
	   }
	   else if(y2==y1){
	   	kk='|';
	    if(x1>x2){
		  int temp=x1;
		  x1=x2;
		  x2=temp;
	   } 
	   	for(int i=x1;i<=x2;i++){
	   	      if(ch[i][y1]=='-')ch[i][y1]='+';
	   	      if(ch[i][y1]=='+')continue;
			   ch[i][y1]=kk;
		  }
	   }
	   
}
void deal1(int x,int y,char kk){
	for(int i=0;i<=3;i++){
		int xx=x+cg[i][0];
		int yy=y+cg[i][1];
		if(vst[xx][yy])continue;
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		if(ch[xx][yy]=='+'||ch[xx][yy]=='-'||ch[xx][yy]=='|')continue;
		ch[xx][yy]=kk;
		vst[xx][yy]=true;
		deal1(xx,yy,kk);
	}
}
int main(){
	int q;
	cin>>m>>n>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ch[i][j]='.';
		}
	}
	while(q--){
	    int w;
	    cin>>w;
	    if(w==1){
	    	int a,b;
			char c;
			cin>>a>>b>>c;
			int temp=a;
			a=n-1-b;
			b=temp;
			memset(vst,false,sizeof(vst));
			if(ch[a][b]=='+'||ch[a][b]=='-'||ch[a][b]=='|')continue;
			ch[a][b]=c;
			deal1(a,b,c); 
		}else{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			deal2(a,b,c,d);
	}
}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ch[i][j];
		}
		cout<<endl;
	}
	return 0;
}
