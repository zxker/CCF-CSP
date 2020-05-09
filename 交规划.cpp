#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 10010;
const int MAX_M = 100010;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, w, next;
}e[MAX_M];
int p[MAX_N], eid, n,m,ans=0,pre[MAX_N];
void mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
int lu[MAX_N][MAX_N];
void insert(int u, int v, int w) { 
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
int dist[MAX_N];  
bool vst[MAX_N];  
struct node {
    int u;
    int dist;
    node(int _u, int _dist) : u(_u), dist(_dist) {}
    bool operator < (const node &x) const {
        return dist > x.dist;
    }
};
typedef pair<int, int> PII;
set<PII, less<PII> > min_heap;
bool dijkstra(int s) {
    // 初始化 dist、小根堆和集合 U
    memset(vst, 0, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    min_heap.insert(make_pair(0, s));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        if (min_heap.size() == 0) {  // 如果小根堆中没有可用顶点，说明有顶点无法从源点到达，算法结束
            return false;
        }
        // 获取堆顶元素，并将堆顶元素从堆中删除
        auto iter = min_heap.begin();
        int v = iter->second;
        min_heap.erase(*iter);
        vst[v] = true;
        // 进行和普通 dijkstra 算法类似的松弛操作
        for (int j = p[v]; j != -1; j = e[j].next) {
            int x = e[j].v;
            if(dist[v] + e[j].w == dist[x]&&lu[pre[x]][x]>e[j].w){
            	   pre[x]=v;
            	   continue;
			}
            if (!vst[x] && dist[v] + e[j].w < dist[x]) {
                // 先将对应的 pair 从堆中删除，再将更新后的 pair 插入堆
                min_heap.erase(make_pair(dist[x], x));
                dist[x] = dist[v] + e[j].w;
                pre[x]=v;
                min_heap.insert(make_pair(dist[x], x));
            }
        }
    }
    return true;  // 存储单源最短路的结果
}
int  main(){
	cin>>n>>m;
	mapinit();
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(lu[a][b])continue;
		insert(a,b,c);
		insert(b,a,c);
		lu[a][b]=lu[b][a]=c;
	}
	memset(pre,0,sizeof(pre));
	dijkstra(1);
	for(int i=1;i<=n;i++){
	//	cout<<lu[pre[i]][i]<<endl;
		ans+=lu[i][pre[i]];
	}
	cout<<ans<<endl;
	return 0;
}
