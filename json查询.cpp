#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<regex,string>>trans={
    {regex(" "),""},
    {regex("\\\\\""),"\""},
    {regex("\\\\\\\\"),"\\"}  
};
unordered_map<string,string>mp;
string s="";
vector<string>veq;
int main(){
	int n,m;
	cin>>n>>m;
	getchar();
	while(n--){
	  	string ip;
	  	getline(cin,ip);
	    s+=ip;
	}
    for(auto it:trans){
     	s=regex_replace(s,it.first,it.second);
	}
	string ipkey="",ipvalue="";
	int flag=0;
	int flag2=0;
   // cout<<s<<endl;
	for(int i=1;i<s.size();i++){
		if(s[i]=='}'){
					if(veq.size()>=1)veq.pop_back();
					continue;
		}
		  if(flag==0){
		  	  if(s[i]=='"'){
		  	  	    i++;
		  	       while(s[i+1]!='"'&&s[i+2]!=':'){
		  	       	   ipkey+=s[i];
		  	       	   i++;
					}
					ipkey+=s[i];
				//	cout<<ipkey<<endl;
					i=i+2;
					flag=1;	
			  }
			  continue;
		  }
		  if(flag==1){
		  	   if(s[i]=='{'){
		  	   	    string temp="";
		    		for(int it=0;it<veq.size();it++){
		    			if(it==0)temp+=veq[it];
		    			else temp+="."+veq[it];
					}
					if(veq.size()>=1)temp+="."+ipkey;
					else temp=ipkey;
		  	   	   mp[temp]="{}";
		  	   	   veq.push_back(ipkey);
		  	   	   flag=0;
		  	   	   ipkey="";
		  	   	   continue;
				
				}
				if(flag2==0){
					if(s[i]=='"'){
		  	  	      i++;
		  	          while(1){
		  	       	     ipvalue+=s[i];
		  	       	     if(s[i+1]=='"'&&s[i+2]==',')break;
		  	       	     if(s[i+1]=='"'&&s[i+2]=='}')break;
		  	       	     i++;
					   }
					   //ipvalue+=s[i];
					 //  cout<<ipvalue<<endl; 
					   i=i+1;
					   flag2=1;	
			       }
		    	}
		    	if(flag2){
		    		string temp="";
		    		for(int it=0;it<veq.size();it++){
		    			if(it==0)temp+=veq[it];
		    			else temp+="."+veq[it];
					}
					if(temp!="")temp+="."+ipkey;
					else temp=ipkey;
				//	cout<<temp<<" "<<ipvalue<<endl; 
					mp[temp]=ipvalue;
					ipkey="";
					ipvalue="";
					flag=0;
					flag2=0;
				}
		  }
	}
	while(m--){
		string ip;
		cin>>ip;
		if(mp.find(ip)==mp.end()){
			cout<<"NOTEXIST"<<endl;
		}else if(mp[ip]=="{}"){
			cout<<"OBJECT"<<endl;
		}else{
			cout<<"STRING"<<" "<<mp[ip]<<endl;
		}
	}   
	return 0;
}
/*
1 10
{"a":{"b":"c","zxk":{"ty":"df","109":"sds"}}}
*/
