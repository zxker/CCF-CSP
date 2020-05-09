#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int>L;
bool Del_Min(int value){
  if(L.size()==0)return false;
  value=L[0];
  int pos=0;
  for(int i=0;i<L.size();i++){
  if(L[i]<value){
       value=L[i];
        pos=i;
    }
  }
   L[pos]=L[L.size()-1]; 
   L.pop_back();
   return true;
} 
int main(){
	cout<<"删除之前："<<endl; 
	for(int i=1;i<=10;i++){
		L.push_back(i);
		cout<<i<<endl; 
	}
	Del_Min(0);
	cout<<"删除之后："<<endl; 
	for(int i=0;i<L.size();i++){
		cout<<L[i]<<endl;
	}
	return 0;
}


            

