#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	double val;
	ll cnt;
	int idd;//第几行输入的 
	node(double vl,ll cn,int id)
	{
		val=vl;
		cnt=cn;
		idd=id;
	}
	bool operator <(const node &a)const//价格小的排在前面 
	{
	       return val<a.val;
	}
};
vector<node>ve[2];
int main()
{
	string s;
	double value;
	ll sum;
	int id=0,row;
	while(cin>>s)
	{
		if(s=="zxk")break; 
		if(s=="buy")
		{
			id++;
			cin>>value>>sum;
			ve[0].push_back({value,sum,id});
		}
		else if(s=="sell")
		{
			id++;
			cin>>value>>sum;
			ve[1].push_back({value,sum,id});
		}
		else if(s=="cancel")
		{
			cin>>row;
			{
				int flag=0;
				while(true)
				{
					for(vector<node>::iterator it=ve[0].begin();it!=ve[0].end();++it)
					{
						if((*it).idd==row)
						{
							ve[0].erase(it);
							flag=1;
							break;
						}
					}
					if(flag)
					{
						break;
					}
					for(vector<node>::iterator it=ve[1].begin();it!=ve[1].end();++it)
					{
						if((*it).idd==row)
						{
							ve[1].erase(it);
							flag=1;
							break;
						}
					}
					if(flag)
					{
						break;
					}
				}
			}
			
		}
	}
	sort(ve[0].begin(),ve[0].end());
	sort(ve[1].begin(),ve[1].end());
	ll sum1;
	double money;
	for(int i=ve[0].size()-1;i>=1;i--)//买的数量 
	{
		ve[0][i-1].cnt+=ve[0][i].cnt;
		//cout<<"买"<<ve[0][i-1].cnt<<endl;
	}
	
	for(int j=1;j<ve[1].size();j++)//卖的数量 
	{
		ve[1][j].cnt+=ve[1][j-1].cnt;
		//cout<<"卖"<<ve[1][j].cnt<<endl;
	}
	for(int i=ve[0].size()-1,j=0;i>=0&&j<ve[1].size();)
	{
		if(ve[0][i].val>=ve[1][j].val)
		{
			sum1=min(ve[0][i].cnt,ve[1][j].cnt);
			money=max(money,min(ve[0][i].val,ve[1][j].val)); 
			if(ve[0][i].cnt<ve[1][j].cnt)
			{
				i--;
			}
			if(ve[0][i].cnt>ve[1][j].cnt)
			{
				j++;
			}
			else
			{
				i--;
				j++;
			}
		}
		else
		{
			break;
		}
	}
	printf("%.2f %lld",money,sum1);
	return 0;
}
/*
buy 9.25 100
buy 8.88 175
sell 9.00 1000
buy 9.00 400
sell 8.92 400
cancel 1
buy 100.00 50
*/

