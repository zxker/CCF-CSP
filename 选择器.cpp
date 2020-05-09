#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<regex,string>>trans={
      {regex ("(\\.)([a-zA-Z0-9])"),"$1 $2"}
};
struct po{
	string lable;
	string id="";
	int l;
	po(string x,string y,int xx){
		lable=x;
		id=y;
		l=xx;
	}
};
struct poo{
	string lable;
	string id="";
	poo(string x,string y){
		lable=x;
		id=y;
	}
};
int flag=0;
vector<po>ve;
vector<string>intemp;
vector<int>ans;
vector<poo>query;
string tolow(string x){//转化为小写 	
	for(int i=0;i<x.size();i++)x[i]=tolower(x[i]);
	return x;
}
void tostr(string line,string ch){//以ch分割字符串 
	int t;
	intemp.clear(); 
    for(t = line.find(ch); t != string::npos; t = line.find(ch))
    {
        intemp.push_back(line.substr(0,t));
        line = line.substr(t+1);
    }
    intemp.push_back(line);
    return;
}
bool judge(string x1,string y1,string x2,string y2){
	if(x2==""&&y2==y1)return true;
	if(y2==""&&x1==x2)return true;
	return false;
}
void dfs(int ll,int num,int level){
	if(num==query.size()){
		flag=1;
		return;
	}
	int ed=query.size();
	for(int i=ll-1;i>=1;i--){
		if(ve[i].l>=level)continue;
		if(judge(ve[i].lable,ve[i].id,query[ed-num-1].lable,query[ed-num-1].id)){
			dfs(i,num+1,ve[i].l);
			if(flag)return;
		}
	}
}
int n,m;
int main(){
	cin>>n>>m;
	ve.push_back(po("","",0));
	getchar();
	for(int i=1;i<=n;i++){
		string ip;
		getline(cin,ip);
		for(auto it:trans){
			ip=regex_replace(ip,it.first,it.second);
		}
		tostr(ip," ");
		int num=0;
		
		for(int z=0;z<intemp.size();z++){
			if(intemp[z][0]=='.'){
				num=intemp[z].size();
				continue; 
			}
			if(intemp[z][0]=='#'){
				ve[i].id=intemp[z];
		        continue;
			}
			string temp=tolow(intemp[z]);
			ve.push_back(po(temp,"",num));
		}
	}
	while(m--){
		string q;
		getline(cin,q);
		tostr(q," ");
		ans.clear();
		query.clear();
		for(int z=0;z<intemp.size();z++){
		        string temp=intemp[z];
				if(temp[0]=='#'){
		            query.push_back(poo("",temp));
				}else{
				   tolow(temp);
				   query.push_back(poo(temp,""));	
				} 	
		}
		int ed=query.size()-1;
		for(int i=1;i<=n;i++){
			flag=0;
			if(judge(ve[i].lable,ve[i].id,query[ed].lable,query[ed].id)){
				dfs(i,1,ve[i].l);
				if(flag){
		             ans.push_back(i);
				  }
			}
		}
	if(ans.empty()){
		cout<<0<<endl;
		continue;
	}else{
		cout<<ans.size();
		for(auto k:ans){
			cout<<" "<<k;
		}
		cout<<endl;
	}
	}
	return 0;
}
/*
11 10
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
p
#subtitle
h3
div p
div div p
*/

