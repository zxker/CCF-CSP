
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int p[500010]; //ȫ��������Ϊ���鼯
 
typedef struct Edge //���������
{
	int u, v, w;
}Edge;
 
struct cmp //�Զ������ȼ����еıȽϺ���
{
	bool operator()(const Edge &a, const Edge &b)
	{
		return a.w > b.w; //��ȨֵС�����ȼ���
	}
};
 
int find(int x) //���鼯���Ҹ��ڵ�
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
 
int main()
{
	int tmax = 0; //������
	int n, m, root; //rootֻ�������ݣ��������������޹�
	cin >> n >> m >> root;
	for(int i = 0; i < n + 1; i++) //��ʼ�����鼯��ע����Ŀ���˳���Ǵ�1��ʼ������0
		p[i] = i;
	priority_queue<Edge, vector<Edge>, cmp> pq_e;
	for(int i = 0; i < m; i++) //����ߵ����ݲ��洢�����ȼ�������
	{
		Edge e;
		int u, v, w;
		cin >> u >> v >> w;
		e.u = u, e.v = v, e.w = w;
		pq_e.push(e);
	}
	for(int i = n - 1; i > 0;) //����MST�ı����ض��Ƚ������1�����ɴ˿���ѭ��
	{
		Edge e = pq_e.top(); //����ͷ��Ԫ��һ��������δ���ʱ���Ȩֵ��С��
		pq_e.pop();
		int u = e.u;
		int v = e.v;
		int ru = find(u);
		int rv = find(v);
		//�ڲ��鼯�в��Ҵ˱ߵ����˵����Ƿ��й�ͬ�ĸ���������˵�������˱��������ֻ�·����Ӧ��ȥ
		if(ru == rv) continue;
		//û����˵���˱߿�������MST�У�������Ŀ��Ҫ�����յĽ��һ�����������MST�бߵ�Ȩֵ
		//����Ϊ���ȼ������е�Ԫ���Ѱ�����СȨֵ���ȵķ�ʽ���к��ˣ���˿��Բ��Ͻ��и��ǲ���
		//���ⲻҪ���ǽ����˵��������Ϻϲ���һ��
		else
		{
			p[ru] = rv; //�ϲ�����
			tmax = e.w; //���ϸ���ֱ���˳�ѭ��
			i--;
		}
	}
	cout << tmax;
	return 0;

} 
