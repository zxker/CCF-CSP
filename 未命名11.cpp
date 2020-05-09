#include<bits/stdc++.h>
using namespace std;
struct po{
	int x1,y1,x2,y2;
	int ans; 
	int pos;
	po(int xx1,int yy1,int xx2,int yy2,int p,int dd){
		x1=xx1;
		y1=yy1;
		x2=xx2;
		y2=yy2;
		pos=p;
	    ans=dd;
	}
	bool operator<(const po&A)const{
		return pos<A.pos;
	}
};
priority_queue<po>q;
queue<po>qq;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		q.push(po(a,b,c,d,i,i));
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		int flag=0;
		while(!qq.empty()){
			po temp=qq.front();
			qq.pop();
			q.push(temp);
		}
		while(!q.empty()){
			po now=q.top();
			q.pop();	
			int x1=now.x1;
			int y1=now.y1;
			int x2=now.x2;
			int y2=now.y2;
			int ans=now.ans;
			if((a>=x1&&a<=x2)&&(b>=y1&&b<=y2)){
				cout<<ans<<endl;
				flag=1;
				now.pos=n; 
				q.push(now);
				while(!qq.empty()){
					po temp=qq.front();
					qq.pop();
					temp.pos--;
					q.push(temp);
				}
				break;
			}
			qq.push(now);
		}
		if(!flag)cout<<"IGNORED"<<endl;	
	}
	return 0;
}
