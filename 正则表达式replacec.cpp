#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string str;
	cin>>str;
   regex e("[[:w:]]+@[[:w]]+\.com"); 
   cout<<regex_replace(str,e,"133")<<endl;;			
	return 0;
}
