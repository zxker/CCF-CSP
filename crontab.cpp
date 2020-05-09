#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mintime,maxtime;
const int year=(int)(1e8),month=(int)(1e6),day=10000,hour=100;
unordered_map<string,int>totimemap={
    {"jan",1},{"feb",2},{"mar",3},{"apr",4},{"may",5},{"jun",6},
    {"jul",7},{"aug",8},{"sep",9},{"oct",10},{"nov",11},{"dec",12},
    {"sun",0},{"mon",1},{"tue",2},{"wed",3},{"thu",4},{"fri",5},{"sat",6}
};
const int daytime[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<string>ve;
string htime[6];
set<int>zxk[6];
map<ll,vector<int>>ansmap;
int dealnum(string x){
	if(isdigit(x[0])){
		return stoi(x);
	}
	for(int i=0;i<x.size();i++){
		x[i]=tolower(x[i]);
	}
	return totimemap[x];
}	

int isyear(int y,int m){
	if(y%400==0||(y%4==0&&y%100!=0)){
		if(m==2)return 29;
	}
	else return daytime[m];
}
int get(int y,int m,int d){
	if(m==1||m==2){
		m+=12;
		y-=1;
	}
	int temp=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;
	if(temp==7)return 0;
	return temp;
}
void dealtime(){
	for(int i=1;i<=5;i++){
		zxk[i].clear();
	}
	for(int i=1;i<=5;i++){
		if(htime[i]=="*"){
			int bx,endx;
			if(i==1){
				bx=0;endx=59;
			}
			else if(i==2){
				bx=0;endx=23;
			}
			else if(i==3){
				bx=1;endx=31;
			}
			else if(i==4){
				bx=1;endx=12;
			}
			else {
				bx=0;endx=6;
			}
			for(int j=bx;j<=endx;j++){
				zxk[i].insert(j);
			}
		}else{ 
			int j,k;
			for(j=0;;j=k+1){
				k=htime[i].find(',',j);
				string temp;
				if(k==string::npos){
					temp=htime[i].substr(j);
				}else{
					temp=htime[i].substr(j,k-j);
				}
			    int k1,bx,endx;
			    k1=temp.find('-',0);
			    if(k1==string::npos){
			    	bx=endx=dealnum(temp);
				}else{
					bx=dealnum(temp.substr(0,k1));
					endx=dealnum(temp.substr(k1+1));
				}
	            for(int kk=bx;kk<=endx;kk++){
	            	zxk[i].insert(kk);
				}			
				if(k==string::npos)break;
			} 
			
		}
	}
	
}
void anstime(int x){
	for(int y=mintime/year;y<=maxtime/year;y++){
		for(int m:zxk[4]){
			for(int d:zxk[3]){
				if(d>isyear(y,m))continue;
				int xingqi=get(y,m,d);
				if(find(zxk[5].begin(),zxk[5].end(),xingqi)!=zxk[5].end()){
					   for(int h:zxk[2]){
					   	  for(int mi:zxk[1]){
					   	  	   ll temp=(long long)y*year+m*month+d*day+h*hour+mi;
                            if(temp>=mintime&&temp<maxtime)
                                ansmap[temp].push_back(x);
							 }
					   }
				}
			}
		}
	}
}
int main(){
	int n;
	cin>>n>>mintime>>maxtime;
	ve.resize(n+1);
 	for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
        	cin>>htime[j];
		}
		cin>>ve[i];
		dealtime();
		anstime(i);
	}     
	for(auto&x:ansmap){
		for(auto y:x.second){
			cout<<x.first<<" "<<ve[y]<<endl;
		}
	}
	return 0;
}
