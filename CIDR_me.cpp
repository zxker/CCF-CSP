#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IP{
	string ip="";
	int qth=-1;
	bool operator<(const IP &A)const{
	    if(ip!=A.ip)return ip<A.ip;
	    return qth<A.qth;
	}
};
list<IP>li;
IP ipchange(string s){
	IP res;
	string k="";
	int v[8]={1,2,4,8,16,32,64,128};
	for(int i=0;i<=s.size();i++){
		if(s[i]==s.size()||!isdigit(s[i])){
			int num=stoi(k);
			for(int j=7;j>=0;j--){
				if(num>=v[j]){
					res.ip+="1";
					num-=v[j]; 
				}
				else res.ip+="0";
			}
			k="";
			if(s[i]=='/'){
				res.qth=stoi(s.substr(i+1));
				break;
			}			
		}else{
			k+=s[i];
		}	
	}
	if(res.qth==-1){
		res.qth=res.ip.size();
	}
	while(res.ip.size()<32){
		res.ip+="0";
	}
    return res;	
}
bool union1(IP&a,IP&b){
	if(a.qth>b.qth)return false;
	for(int i=0;i<a.qth;i++){
		if(a.ip[i]!=b.ip[i]){
			return false;
		}
	}
	return true;
}
bool union2(IP&a,IP&b){
	if(a.qth!=b.qth){
		return false;
	}
	for(int i=0;i<a.qth-1;i++){
		if(a.ip[i]!=b.ip[i])return false;
	}
	return a.ip[a.qth-1]!=b.ip[b.qth-1];
}
void merge1(){
	auto i=li.begin(),j=li.begin();
	for(++j;j!=li.end();){
		if(union1(*i,*j)){
			j=li.erase(j);	
		}else{
			++i;
			++j;
		}
	}
} 
void merge2(){
	auto i=li.begin(),j=li.begin();
	for(++j;j!=li.end();){
		if(union2(*i,*j)){
			j=li.erase(j);
			--(*i).qth;
			if(i!=li.begin()){
				i--;
				j--;
			}
		}else{
			++i;
			++j;
		}
	}
}
int main(){
	int N;
	cin>>N;
	while(N--){
		string input;
		cin>>input;
		li.push_back(ipchange(input));
	}
	li.sort();
	merge1();
	merge2();
	for(auto&i:li){
		for(int j=0;j<4;j++){
			int sum=0;
			for(int k=0;k<8;k++){
				sum=sum*2+(i.ip[k+j*8]-'0');
			}
			printf("%d%s",sum,(j<3?".":"/"));
		}
		printf("%d\n",i.qth);
	}
	return 0;
}
