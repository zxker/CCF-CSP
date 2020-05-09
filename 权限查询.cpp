#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct cate{
	string nm;
	int level=-1;
};
unordered_map<string,vector<cate>>role;
unordered_map<string,vector<string>>user;
int p,r,u,q;
cate dealname(string x){
	cate re;
	int j=x.find(':');
	if(j==string::npos){
		re.nm=x;
		re.level=-1;
	}else{
		re.nm=x.substr(0,j);
		re.level=x.back()-'0';
    }
	return re;
}
void findin(string x,cate y){
	if(user.find(x)==user.end()){
		cout<<"false"<<endl;
		return ;
	}
	int ans=-1;
	int flag=0;
	for(int i=0;i<user[x].size();i++){
		for(auto it:role[user[x][i]]){
		//	cout<<it.nm<<" "<<y.nm<<endl;
			if(y.nm==it.nm){
			//	cout<<it.level<<" "<<y.level<<endl;
				if(it.level>=y.level){
					flag=1;
					ans=max(ans,it.level);
				//	cout<<ans<<endl;
				}
			}
		}
	}
	if(flag==1){
		if(y.level==-1){
			if(ans!=-1)cout<<ans<<endl;
			else cout<<"true"<<endl; 
        }
		else {
			cout<<"true"<<endl;
		} 
	}else{
		cout<<"false"<<endl;
	} 
}
int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		string ip;
		cin>>ip;
	}
	cin>>r;
	for(int i=1;i<=r;i++){
		string rolename;
		int numcate;
		cin>>rolename>>numcate;
		for(int j=1;j<=numcate;j++){
			string catename;
			cin>>catename;
	        role[rolename].push_back(dealname(catename)); 
		}
	}
	cin>>r;
    for(int i=1;i<=r;i++){
    	string username;
    	int num;
    	cin>>username>>num;
    	for(int j=1;j<=num;j++){
    		string rolename;
    		cin>>rolename;
    		user[username].push_back(rolename);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		string zxk,wcate;
		cin>>zxk>>wcate;
		cate w=dealname(wcate);
		findin(zxk,w);
	}
	return 0;
}
