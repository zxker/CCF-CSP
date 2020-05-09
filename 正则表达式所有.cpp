#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	while(true){
		cin>>str;
		//regex e("abc.",regex_constants::icase);
	    //regex e("abc?");
		// regex e("abc*");
		//regex e("abc+");
		//regex e("ab[cd]*");
	//	regex e("ab[^cd]*");
		//regex e("^cd.*");
		//regex e("ab[cd]{3}");
		//regex e("ab[cd]{3,}");
		//regex e("abc|de[fg]");
	//regex e("(abc)da+\\1");
	  //regex e("(ab)c(de+)\\2\\1");
	     regex e("[[:w:]]+@[[:w:]]+\.com");//[[:w:]]word character;digit;num or underscore
		bool match=regex_match(str,e);
		if(match){
			cout<<"yes"<<endl;
		}else {
			cout<<"no"<<endl;
		}
		/*regex e("abx");
		//regex e("^abc.+",regex_constants::greg);
		//^ ->begin  &->end;
 		/bool match=regex_search(str,e);
		if(match){
			cout<<"yes"<<endl;
		}else {
			cout<<"no"<<endl;
	    }*/
	
	}
	return 0;
} 
