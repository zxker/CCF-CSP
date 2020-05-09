
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int p[500010]; //全局数组作为并查集
 
typedef struct Edge //定义边类型
{
	int u, v, w;
}Edge;
 
struct cmp //自定义优先级队列的比较函数
{
	bool operator()(const Edge &a, const Edge &b)
	{
		return a.w > b.w; //边权值小的优先级高
	}
};
 
int find(int x) //并查集查找根节点
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
 
int main()
{
	int tmax = 0; //输出结果
	int n, m, root; //root只读入数据，后续程序与其无关
	cin >> n >> m >> root;
	for(int i = 0; i < n + 1; i++) //初始化并查集，注意题目结点顺序是从1开始而不是0
		p[i] = i;
	priority_queue<Edge, vector<Edge>, cmp> pq_e;
	for(int i = 0; i < m; i++) //读入边的数据并存储到优先级队列中
	{
		Edge e;
		int u, v, w;
		cin >> u >> v >> w;
		e.u = u, e.v = v, e.w = w;
		pq_e.push(e);
	}
	for(int i = n - 1; i > 0;) //由于MST的边数必定比结点数少1，故由此控制循环
	{
		Edge e = pq_e.top(); //队列头部元素一定是所有未访问边中权值最小的
		pq_e.pop();
		int u = e.u;
		int v = e.v;
		int ru = find(u);
		int rv = find(v);
		//在并查集中查找此边的两端点编号是否有共同的根，若有则说明若将此边纳入会出现回路，故应舍去
		if(ru == rv) continue;
		//没有则说明此边可以纳入MST中，由于题目的要求，最终的结果一定是最后纳入MST中边的权值
		//又因为优先级队列中的元素已按照最小权值优先的方式排列好了，因此可以不断进行覆盖操作
		//另外不要忘记将两端点所属集合合并到一起！
		else
		{
			p[ru] = rv; //合并集合
			tmax = e.w; //不断覆盖直至退出循环
			i--;
		}
	}
	cout << tmax;
	return 0;

} 
