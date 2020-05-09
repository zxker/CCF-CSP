#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;
unordered_map<char,string>ans;
set<char>st;//´æ½á¹û
string str; 
int main(){
	int n;
	cin>>str>>n;
	for(int i=0;i<str.size();i++){
		if(str[i]==':')continue;
		if(i+1!=str.size()){
			if(str[i+1]==':'){
				mp[str[i]]=1;
				continue;
			}
			mp[str[i]]=-1;
		}
		mp[str[i]]=-1;
	}
	string ip;
	getchar();
	for(int i=1;i<=n;i++){
		st.clear();
		int num=0;
		getline(cin,ip);
		int j=0,k;
		for(;;j=k+1){
			k=ip.find(' ',j);
			string temp;
			if(k!=string::npos)temp=ip.substr(j,k-j);
			else temp=ip.substr(j);
			num++;
			if(num==1){
				if(k==string::npos)break;
				continue;
			}
			if(temp[0]=='-'){
				temp.erase(0,1);
			}
			if(temp.size()!=1)break; 
			if(mp.find(temp[0])!=mp.end()){
				if(mp[temp[0]]==-1){
					st.insert(temp[0]);
				}else{
					if(k==string::npos)break;
					j=k+1;
					k=ip.find(' ',j);
					string temp1;
					if(k!=string::npos)temp1=ip.substr(j,k-j);
			        else temp1=ip.substr(j);
			        int ff=0;
					for(int it=0;it<temp1.size();it++){
						if(!('a'<=temp1[it]&&temp1[it]<='z')&&temp1[it]!='-'&&!(temp1[it]<='9'&&temp1[it]>='0')){
							ff=1;
							break;
						}
					}
					if(ff==0){
						ans[temp[0]]=temp1;
						st.insert(temp[0]);
					}
					if(ff==1)break;
				}
			}else break;
			if(k==string::npos)break;
		}
		cout<<"Case "<<i<<":";
		for(auto it:st){
			cout<<" "<<"-"<<it;
			if(mp[it]==1){
				cout<<" "<<ans[it];
			}
		}
		cout<<endl;
	}
	return 0;
}
