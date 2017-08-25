#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
void dfs(vector<int> & vec,unordered_map<int, unordered_set< int > >& p_map, unordered_set<int>& markedSet,int node)
{
	markedSet.insert(node);
	for (auto iter = p_map[node].begin(); iter != p_map[node].end(); ++iter)
	{
	     if (markedSet.find(*iter)==markedSet.end())
	     {
			 dfs(vec, p_map, markedSet, *iter);
		 }	
	}
	vec.push_back(node);
}
int main()
{
	//拓扑排序是深度优先搜索完成顺序的逆后序
	vector<pair< int, int> > inputVec = { { 1, 2 }, { 1, 3 }, { 3, 4 }, { 2, 4 }, { 2, 6 }, { 2, 5 }, {4,5},{ 5, 7 } };
	unordered_map<int, unordered_set< int > > m_map;
	vector<int> vec;
	unordered_set<int> markedSet;
	for (auto iter = inputVec.begin(); iter != inputVec.end();++iter)
	{
		m_map[(*iter).first].insert((*iter).second);
	}
	for (auto iter = m_map.begin(); iter != m_map.end();++iter)
	{
		if (markedSet.find((*iter).first)==markedSet.end())
		{
			//markedSet.insert((*iter).first);
			dfs(vec, m_map, markedSet, (*iter).first);
		}
	}
	reverse(vec.begin(), vec.end());
	getchar();
	return 0;
}