#pragma once
#include "Graph.h"
class DepthFirstPaths
{
public:
	DepthFirstPaths(Graph G,int s);
	void dfs(Graph G,int v);
	bool hasPathTo(int v){return marked[v];}

	vector <int> pathTo(int v);
private:
	vector<bool> marked;
	vector<int> edgeTo;
	int s;
};