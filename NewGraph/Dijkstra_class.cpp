//当权重值非负时，可以使用这个算法，当无环时，使用拓扑排序可以有更好效果。
#include<unordered_set>
#include<unordered_map>
#include <queue>
#include <iostream>
#include <map>
//#include <priority_queue>//没有这个头文件，在<queue>中
#include<vector>
using namespace std;
//priority_queue没有迭代器，没有find操作，无法确认某个数是否在队列中，使用不便
class Distance
{
public:
	Distance(int p_node, double p_weight) :node(p_node), weight(p_weight)
	{

	}
	bool operator<( const Distance& rhs) const //后面这个const必须加，否则无法编译，参数中的const可以不加
	{
		return weight < rhs.weight;
	}
	int node;
	double weight;
};
void relax(unordered_map<int, vector< pair<int, double >> > & p_map, unordered_map<int, double>& disMap,
	priority_queue<Distance>& Queue, Distance & dis, unordered_map<int, int>& edge)
{
	for (auto iter = p_map[dis.node].begin(); iter != p_map[dis.node].end();++iter)
	{
		if (disMap[(*iter).first]>disMap[dis.node] + (*iter).second)
		{
			disMap[(*iter).first] = disMap[dis.node] + (*iter).second;
			Queue.push(Distance((*iter).first, disMap[(*iter).first]));
			               //本来如果节点在队列中可以只更新其值不必重复加入，可惜C++的priority_queue未实现该操作
			edge[(*iter).first] = dis.node;
		}
	}
}
vector<int> pathTo(int x, unordered_map<int, int>& edge)
{
	vector<int > result;
	while (edge.find(x)!=edge.end())
	{
		result.push_back(x);
		x = edge[x];
	}
	result.push_back(x);
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	
	vector<pair< int, int> > inputVec = { { 4, 5 }, { 5, 3 }, { 4, 7 }, { 5, 7 }, { 7, 5 }
	, { 5, 1 }, { 0, 4 }, { 0, 2 }, { 7, 3 }, { 1, 3 }, { 2, 7 }, { 6, 2 }, { 3, 6 }, { 6, 0 }, { 6, 4 } };
	vector<double >     inputWeight = { 0.35, 0.35, 0.37, 0.28, 0.28, 0.32, 0.38, 0.26, 0.39, 0.29, 0.34, 0.4, 0.52, 0.58, 0.93 };
	if (inputVec.size()!=inputWeight.size())
	{
		cout << "输入大小不一致" << endl;
	}
	unordered_map<int, vector< pair<int,double >> > m_map;  //记录从一个节点开始的边和相应权重
	unordered_set<int> nodeVec;                             //记录所有节点
	unordered_map<int, double> distToMap;                    //记录从单源节点开始的距离
	unordered_map<int, int> edgeTo;                          //记录路径
	for (int i = 0; i < (int)inputVec.size(); ++i)
	{
		nodeVec.insert(inputVec[i].first);
		nodeVec.insert(inputVec[i].second);
	   m_map[inputVec[i].first].push_back(make_pair(inputVec[i].second, inputWeight[i]));
	}
	int node = 0;                                   //设置开始节点
	distToMap.insert(make_pair(0, 0.0)); //map保证了不会重复插入
	for (auto iter = nodeVec.begin(); iter != nodeVec.end(); ++iter)
	{
		distToMap.insert(make_pair(*iter, INT_MAX));  //将距离初始化为无穷大
	}
	priority_queue<Distance> priorityQueue;
	priorityQueue.push(Distance(0, 0.0));
	while (!priorityQueue.empty())
	{
		Distance temp = priorityQueue.top();
		priorityQueue.pop();
		relax(m_map, distToMap, priorityQueue, temp,edgeTo); 
		                                   //每次取distTo最小的节点，放松该节点出发的每一条边
	}
	vector<int> path1 = pathTo(1, edgeTo); //求取0到具体节点的路径
	vector<int> path2 = pathTo(6, edgeTo);
	getchar();
	return 0;
}