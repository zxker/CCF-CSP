#include<bits/stdc++.h>
using namespace std; 
const int MAXN=100+10;
const int MAXM=10000+10;
bool vis[MAXN];
int cnt[MAXN];
int que[MAXN];
int dist[MAXN];
struct po{
	int v,len;
}; 
vector<po>ve[MAX_N];
bool SPFA(int start,int n) 
{
    int front=0,rear=0;
    for(int v=1;v<=n;v++)
    {
        if(v==start)
        {
            que[rear++]=v;
            vis[v]=true;
            cnt[v]=1;
            dist[v]=0;
        }
        else
        {
            vis[v]=false;
            cnt[v]=0;
            dist[v]=INF;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        vis[u]=false;
        if(front>=MAXN)front=0;
        for(int i=0;i<ve[u].size();i++)
        {
            int v=ve[u][i].v;
            int len=ve[u][i].len;
            if(dist[v]>dist[u]+len)
            {
                dist[v]=dist[u]+len;
                if(!vis[v])
                {
                    vis[v]=true;
                    que[rear++]=v;
                    if(rear>=MAXN)rear=0; //循环队列 
                    if(++cnt[v]>n)return false; //存在负环
                }
            }
        }
    }
    return true;
}

