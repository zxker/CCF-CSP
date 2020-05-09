#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=20;
int flag[N+2][N+2];
int num[N+2][N+2];
int pos[N*N];
int x[N+2];
int y[N+2];
int move_x[4]={0,-1,0,1};
int move_y[4]={1,0,-1,0};
int n,cnt=0;
int whfflag=0; 
bool check(int m,int k)
{
	if((m>=0&&m<n)&&(k>=0&&k<n)&&x[m]>0&&y[k]>0&&flag[m][k]==0)
	   return true;
	else
	   return false;
}
void dfs(int m,int k)
{
//	cout<<"m="<<m<<" "<<"k="<<k<<endl;
	//cout<<"n="<<n<<endl;
    if(m==n-1&&k==n-1)
    {
    	for(int i=0;i<n;i++){
    	    if(x[i]!=0)return;    	
	    }
	    for(int i=0;i<n;i++){
    	    if(y[i]!=0)return;    	
	    }
	    whfflag=1;
		return ; 
	}   
	    for(int i=0;i<4;i++)
		{
			m+=move_x[i];
			k+=move_y[i];
			if(check(m,k))
			{
			  //cout<<m<<" "<<k<<endl;
			  x[m]--;
			  y[k]--;
			  flag[m][k]=1;
			  pos[cnt]=num[m][k];
			 //cout<<"pos[cnt]="<<pos[cnt]<<endl;
			  //cout<<"cnt="<<cnt<<" "<<"pos[cnt]="<<pos[cnt]<<endl;
			  cnt++;
			//  cout<<"cnt0="<<cnt<<endl;
			  dfs(m,k);
			  if(whfflag==1)return;
			  x[m]++;
			  y[k]++;
			  flag[m][k]=0;
			  cnt--;
		//	cout<<"cnt1="<<cnt<<endl;
			}	
			m-=move_x[i];
			k-=move_y[i];		
		}
}  
int main()
{
	memset(flag,0,sizeof(flag));
	cin>>n;
	int val=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			num[i][j]=val;
			val++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	x[0]--;
	y[0]--;
	pos[0]=0;
	cnt=1;
	dfs(0,0);
	//cout<<"cnt="<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
		if(i==0)
	       cout<<pos[i]; 
		else cout<<" "<<pos[i];
	}
	return 0;
}
/*
4
2 4 3 4
4 3 3 3
*/

