#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string str;
	while(true){
	   cin>>str;
	   smatch m;
	   regex e("([[:w:]]+)@([[:w:]]+)\.com");
	   bool found=regex_search(str,m,e);
	   
	   cout<<"m.size() "<<m.size()<<endl;
	   for(int i=0;i<m.size();i++){
	   	  cout<<"m["<<i<<"]:str()"<<m[i].str()<<endl; 
	   	 // cout<<"m["<<i<<"]:str()"<<m[].str(i)<<endl; 
	   }
	   //cout<<"m.prefix().str() "<<m.prefix().str()<<endl; 
	  // cout<<"m.suffix().str() "<<m.suffix().str()<<endl; 
	}
	
	
	
	
	return 0;
}
