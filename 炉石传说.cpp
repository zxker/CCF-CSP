#include<bits/stdc++.h>
using namespace std;
struct po{
	int life;
	int attack;
	po(int ll,int att){
		life=ll;
		attack=att;
	}
};
vector<po>ve[2];
int main(){
	int n;
	ve[0].push_back(po(30,0));
	ve[1].push_back(po(30,0));
	cin>>n;
	int now=0,flag=0;
	while(n--){
		string ip;
		int pos,l,att;
		int red,blue; 
		cin>>ip;
		if(ip=="end"){
			now=1-now;
			continue;
		}
		if(ip=="summon"){
			cin>>pos>>att>>l;
			ve[now].insert(ve[now].begin()+pos,po(l,att));
			continue;
		}
		if(ip=="attack"){
			int pk=1-now;
			cin>>red>>blue;
		    ve[now][red].life-=ve[pk][blue].attack;
		    ve[pk][blue].life-=ve[now][red].attack;
		    if(ve[now][red].life<=0)ve[now].erase(ve[now].begin()+red);
		    if(blue==0&&ve[pk][blue].life<=0){
		    	if(now==0)flag=1;
		    	if(now==1)flag=-1;
		    	break;
			}
		    if(ve[pk][blue].life<=0)ve[pk].erase(ve[pk].begin()+blue);
		}
	}
	cout<<flag<<endl;
	cout<<ve[0][0].life<<endl;
	cout<<ve[0].size()-1;
	for(int i=1;i<ve[0].size();i++){
		cout<<" "<<ve[0][i].life;
	}
	cout<<endl;
	cout<<ve[1][0].life<<endl;
	cout<<ve[1].size()-1;
	for(int i=1;i<ve[1].size();i++){
		cout<<" "<<ve[1][i].life;
	}
	cout<<endl;
	return 0;
}
 
