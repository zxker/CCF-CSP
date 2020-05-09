#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int main(){
	int n,k,failsum=0,cur=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	while(failsum!=n-1){
	     cur++;
	     int temp=q.front();
	     q.pop();
	     if(cur%k==0||cur%10==k){
	     		failsum++;
		 }else{
		 	q.push(temp);
		 }
	}
	cout<<q.front()<<endl;
	return 0;
}
