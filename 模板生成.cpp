#include<bits/stdc++.h>
using namespace std;
vector<string>ve;
vector<pair<regex,string>>trans;
int main(){
	int n,m;
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		string str;	
		getline(cin,str);
		ve.push_back(str);
	}
	for(int i=1;i<=m;i++){
		string key,value="",str;
		getline(cin,str);
	    int k=str.find('"',0);
		key=str.substr(0,k-1);
		value=str.substr(k+1);
		value.pop_back();
		trans.push_back(make_pair(regex("\\{\\{ "+key+" }}"),value));
	}
	trans.push_back(make_pair(regex("\\{\\{ ([^\\}]+) }}")," "));
	for(int i=0;i<ve.size();i++){
		for(auto it:trans){
			ve[i]=regex_replace(ve[i],it.first,it.second);
		}
	}
	for(auto it:ve){
		cout<<it<<endl;
	}
	return 0;
}
 
