#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<regex,string>>trans={
   {regex("\\* +(.*)"),"<li>$1</li>"},
   {regex("_([^_]+)_"),"<em>$1</em>"},
   {regex("\\[([^\\]]+)\\]\\(([^\\)]+)\\)"),"<a href=\"$2\">$1</a>"}
};
void initrans(){
	for(int i=1;i<=6;i++){
		trans.push_back(make_pair(regex("^"+string(i,'#')+" +(.*)"),"<h"+to_string(i)+">$1</h"+to_string(i)+">"));
	}
}
vector<vector<string>>ve;
int main(){
   initrans();
   string ip;
   ve.push_back({});	
   while(getline(cin,ip)){
	     if(ip==""){
	         ve.push_back({});    	
		 }else{
		 	ve.back().push_back(ip);
		 }	
	}
	for(int i=0;i<ve.size();i++){
		if(ve[i].empty())continue;
		int type=(ve[i][0][0]=='#'?1:(ve[i][0][0]=='*'?2:3));
		if(type==2)cout<<"<ul>"<<endl;
		if(type==3)cout<<"<p>";
		for(int j=0;j<ve[i].size();j++){
			string temp=ve[i][j];
			//cout<<temp<<endl;
			for(auto it:trans){
				temp=regex_replace(temp,it.first,it.second);
			}
			cout<<temp;
			if(j!=ve[i].size()-1)cout<<endl;
	    }
	    if(type==2)cout<<endl<<"</ul>"<<endl;
		else if(type==3)cout<<"</p>"<<endl;
		else cout<<endl;
	}
	return 0;
} 
