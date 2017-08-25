#include<unordered_set>
#include<unordered_map>
#include <queue>
#include <set>
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
	int anOtherNode(int p_node) const
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
class Graph  //
{
public:
	void addEdge(Edge e)
	{
		m_map[e.node1].insert(e);
	}
	set<Edge> adjSet(int i) 
	{
		return m_map[i];
	}
private:
	unordered_map<int, set<Edge> > m_map;
};
void visit(Graph & G,unordered_set<int> & markedVec,priority_queue<Edge>& Queue,int node)
{
	markedVec.insert(node);
	set<Edge> adjVec = G.adjSet(node);
	
	for (auto iter = adjVec.begin(); iter != adjVec.end(); ++iter)
	{
		if (markedVec.find((*iter).anOtherNode(node))==markedVec.end())
		{
			Queue.push(*iter);
		}
	}
}
int main()
{
	vector<pair< int, int> > inputVec = { { 4, 5 }, { 4, 7 }, { 5, 7 }, { 0, 7 }, { 1, 5 }, { 0, 4 }, { 2, 3 }, { 1, 7 }, { 0, 2 }, { 1, 2 }, { 1, 3 }, { 2, 7 }, { 6, 2 }, { 3, 6 }, { 6, 0 }, {6, 4} };
	vector<double >     inputWeight = { 0.35,0.37,0.28,0.16,0.32,0.38,0.17,0.19,0.26,0.36,0.29,0.34,0.4,0.52,0.58,0.93};
	vector<Edge> edgeVec;
	unordered_map<int, unordered_set<int> > m_map;
	unordered_set<int> nodeVec;
	Graph G;

	for (int i = 0; i < (int)inputVec.size();++i)
	{
		Edge temp(inputVec[i].first, inputVec[i].second, inputWeight[i]);
		G.addEdge(temp);
		G.addEdge(Edge(inputVec[i].second,inputVec[i].first, inputWeight[i]));
		edgeVec.push_back(temp);
		//m_map[inputVec[i].first].insert(inputVec[i].second);
		//m_map[inputVec[i].second].insert(inputVec[i].first);

		nodeVec.insert(inputVec[i].first);
		nodeVec.insert(inputVec[i].second);
	}
	priority_queue<Edge> Queue;
	vector<Edge> result;
	unordered_set<int> markedVec;
	double weightTotal = 0.0;
	visit(G, markedVec, Queue, 0);
	while (!Queue.empty())
	{
		Edge e = Queue.top();
		Queue.pop();
		int v = e.node();
		int w = e.anOtherNode(v);
		if (markedVec.find(v)!=markedVec.end()&&markedVec.find(w)!=markedVec.end())
		{
			continue;
		}
		result.push_back(e);
		if (markedVec.find(v) == markedVec.end())
		{
			visit(G, markedVec, Queue, v);
		}
		if (markedVec.find(w) == markedVec.end())
		{
			visit(G, markedVec, Queue, w);
		}
	}
	double need = 0.0;
	for (auto iter = result.begin(); iter != result.end();++iter)
	{
		need += (*iter).weight;
	}
	getchar();
	return 0;
}