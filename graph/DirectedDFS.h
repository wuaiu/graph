#pragma once
#include <iostream>
#include<vector>
using std::istream;
using std::ifstream;
using std::vector;
#include<algorithm>
#include "Digraph.h"

class DirectedDFS
{
public:
	DirectedDFS(Digraph G,int s);
	DirectedDFS(Digraph G,vector<int> sources);
	void dfs(Digraph g,int V);
	bool isMarked(int v){return marked[v];}
private:
	vector <bool> marked;
};