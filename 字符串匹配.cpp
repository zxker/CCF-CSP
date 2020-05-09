#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int x;
	cin>>x;
	regex e;
	if(x==1){
		e=regex(s);
	}else{
		e=regex(s,regex_constants::icase);
	}
	int N;
	cin>>N;
	while(N--){
		string temp;
		cin>>temp;
		bool findd=regex_search(temp,e);
		if(findd)cout<<temp<<endl;
	}
	
	
	return 0;
}
