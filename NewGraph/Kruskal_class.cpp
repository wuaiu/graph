#include<unordered_set>
#include<unordered_map>
#include <queue>
#include <iostream>
#include <map>
//#include <priority_queue>//没有这个头文件，在<queue>中
#include<vector>
using namespace std;
//priority_queue没有迭代器，没有find操作，无法确认某个数是否在队列中，使用不便
class Edge
{
public:
	Edge(int x, int y, double d)
	{
		node1 = x;
		node2 = y;
		weight = d;
	}
	int node()
	{
		return node1;
	}
	int anOtherNode(int p_node)
	{
		if (node1!=p_node)
		{
			return node1;
		}
		else{
			return node2;
		}
	}
public:
	
	int node1;
	int node2;
	double weight;
	bool operator <(const Edge& edge)const //priority_queue默认是最大堆，想要最小堆就这样定义
	{
		return weight > edge.weight;
	}
};
class WeightQuickunionUF
{
public:
	WeightQuickunionUF(const unordered_set<int>& vec)
	{
		count = vec.size();
		for (auto iter = vec.begin(); iter != vec.end();++iter)
		{
			parentIndex.insert(make_pair(*iter, *iter));
			sizeMap.insert(make_pair(*iter, 1));
		}
	}
	int getCount()
	{
		return count;
	}
	bool isConnected(int i, int j)
	{
		return find(i) == find(j);
	}
	int find(int p)
	{
		while (p!=parentIndex[p])
		{
			p = parentIndex[p];
		}
		return p;
	}
	void connect(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (sizeMap[p]<sizeMap[q])
		{
			parentIndex[i] = j;
			sizeMap[j] += sizeMap[j];
		}
		else
		{
			parentIndex[j] = i;
			sizeMap[i] += sizeMap[j];
		}
	}
private:
	unordered_map<int, int> parentIndex;
	unordered_map<int, int> sizeMap;
	int count;
};
int main()
{
	vector<pair< int, int> > inputVec = { { 4, 5 }, { 4, 7 }, { 5, 7 }, { 0, 7 }, { 1, 5 }, { 0, 4 }, { 2, 3 }, { 1, 7 }, { 0, 2 }, { 1, 2 }, { 1, 3 }, { 2, 7 }, { 6, 2 }, { 3, 6 }, { 6, 0 }, {6, 4} };
	vector<double >     inputWeight = { 0.35,0.37,0.28,0.16,0.32,0.38,0.17,0.19,0.26,0.36,0.29,0.34,0.4,0.52,0.58,0.93};
	vector<Edge> edgeVec;
	unordered_set<int> nodeVec;
	for (int i = 0; i < (int)inputVec.size();++i)
	{
		Edge temp(inputVec[i].first, inputVec[i].second, inputWeight[i]);
		edgeVec.push_back(temp);
		nodeVec.insert(inputVec[i].first);
		nodeVec.insert(inputVec[i].second);
	}
	WeightQuickunionUF uf(nodeVec);
	priority_queue<Edge> Queue;
	vector<Edge> result;
	double weightTotal = 0.0;
	for (auto iter = edgeVec.begin(); iter != edgeVec.end();++iter)
	{
		Queue.push(*iter);
	}
	while (!Queue.empty() && result.size()<edgeVec.size()-1)
	{
		Edge  e = Queue.top();
		Queue.pop();
		int v = e.node();
		int w = e.anOtherNode(v);
		if (uf.isConnected(v,w))
		{
			continue;
		}
		uf.connect(v, w);
		result.push_back(e);
		weightTotal += e.weight;
	}
	double need = 0.0;
	for (auto iter = result.begin(); iter != result.end();++iter)
	{
		need += (*iter).weight;
	}
	getchar();
	return 0;
}