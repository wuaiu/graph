#include "DepthFirstOrder.h"
DepthFirstOrder::DepthFirstOrder(Digraph G)
{
	pre = queue<int> ();
	post =  queue<int> ();
	reversePost = stack<int>();
	marked = vector<bool>(G.getV());
	for (int v = 0;v< G.getV();v++)
	{
		if (!marked[v])
		{
			dfs(G,v);
		}
	}
}
void DepthFirstOrder::dfs(Digraph G,int v)
{
	pre.push(v);

	marked[v] = true;
	vector<int> vec = G.getAdj(v);
	for (auto iter = vec.begin();iter!=vec.end();iter++)
	{
		if (!marked[*iter])
		{
			dfs(G,*iter);

		}
	}
	post.push(v);
	reversePost.push(v);
}