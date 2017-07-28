#include "DepthFirstPaths.h"
DepthFirstPaths::DepthFirstPaths(Graph G,int s)
{
	marked = vector<bool>(G.getV());
	edgeTo =vector<int>(G.getV());
	this->s = s;
	dfs(G,s);
}
void DepthFirstPaths::dfs(Graph G,int v)
{
    marked[v] = true;
	vector<int> adj = G.getAdj(v);
	for (size_t i =0;i < adj.size();i ++)
	{

	int temp = adj[i];
	if (!marked[temp])
	{
			edgeTo[temp] = v;
			dfs(G,temp);
     }

	}
	
}
vector<int> DepthFirstPaths::pathTo(int v)
{
	//if(!hasPathTo(v)) return NULL;
	vector<int> path ;
	
	for (int x = v;x!= s;x=edgeTo[x])
	{
		path.push_back(x);
	}
	path.push_back(s);
	return path;
}