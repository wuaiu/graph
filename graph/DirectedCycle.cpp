#include "DirectedCycle.h"
DirectedCycle::DirectedCycle(Digraph G)
{
  onstack = vector<bool>(G.getV());
  edgeTo = vector<int> (G.getV());
  marked = vector<bool>(G.getV());
  for ( int v = 0;v < G.getV();v++)
  {
	  if (!marked[v])
	  {
		  dfs(G,v);
	  }
  }
}
void DirectedCycle::dfs(Digraph G,int v)
{
	onstack[v] = true;
	marked[v] = true;
	vector<int> vec = G.getAdj(v);
	for(auto iter = vec.begin();iter!= vec.end();iter++)
	{
		if (this->hasCycle())
		{
			return;
		}
		else if(onstack[*iter])
		{
			cycle = stack<int>();
			for (int x= v;x!=*iter;x=edgeTo[x])
			{
				cycle.push(x);
			}
			cycle.push(*iter);
			cycle.push(v);
		}
	}
	onstack[v]=false;

}
