#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char,int>mp;
map<char,string>ans;
string str;
vector<string>ve;
void tostrtok(string line){
	int t; 
    for(t = line.find(" "); t != string::npos; t = line.find(" "))
    {
        ve.push_back(line.substr(0,t));
        line = line.substr(t+1);
    }
    ve.push_back(line);
    return;
}
int main(){
	int n;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]==':')mp[str[i-1]]++;
		else mp[str[i]]++;
	}
	cin>>n;
	getchar();
	string ip;
	for(int ii=1;ii<=n;ii++){
	    ve.clear();
	    ans.clear();
	    getline(cin,ip);
	    tostrtok(ip);
	    for(int i=1;i<ve.size();i++){
	    	if(ve[i][0]=='-'&&ve[i].size()==2&&(ve[i][1]<='z'&&ve[i][1]>='a')&&mp[ve[i][1]]==1){
	    		 ans[ve[i][1]]="";
			}
			else if(ve[i][0]=='-'&&ve[i].size()==2&&(ve[i][1]<='z'&&ve[i][1]>='a')&&mp[ve[i][1]]==2){
				if(i+1==ve.size())break;
				string temp=ve[i+1];
				ans[ve[i][1]]=temp;
				i++;
			}
			else break;
		}
		cout<<"Case "<<ii<<":";
		for(auto it:ans){
			cout<<" -"<<it.first;
			if(it.second!="")cout<<" "<<it.second;
		}
		cout<<endl;
	}
    return 0;
} 
