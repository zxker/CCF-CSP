#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string>ve;
int main(){
    int n;
	cin>>n;
	string now;
	cin>>now;
	getchar();
	for(int i=1;i<=n;i++){
	  string str;
	  ve.clear();
	  getline(cin,str);
	  if(str==""){
	  	cout<<now<<endl;
	  	continue;
	  }
	  if(str[0]!='/')str=now+"/"+str;
	  for(int zz=0;zz<str.size();zz++){
	  	  if(str[zz]=='/')str[zz]=' ';
	  }
	  stringstream s(str);
	  string temp;
	  while(s>>temp){
	  	if(temp==".")continue;
	  	if(temp==".."){
	  	    if(!ve.empty())ve.pop_back();
			continue;	
		}
		ve.push_back(temp);
	  }
	  if(ve.empty())cout<<"/";
	  else{
          for(auto it:ve){
	     	cout<<"/"<<it;
	      }
	  }
	   cout<<endl;
	}	
	return 0;
} 
