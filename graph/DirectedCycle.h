#pragma once

#include <vector>
#include <iostream>
#include<algorithm>
#include <stack>
#include "Digraph.h"
using std::istream;
using std::ifstream;
using std::vector;
using std::stack;
class DirectedCycle
{
public:
	DirectedCycle(Digraph G);
	bool hasCycle(){return cycle.size()!=0;}
	stack<int> getCycle(){return cycle;}
private:
	void dfs(Digraph G,int v);
	vector<bool> marked;
	vector<int> edgeTo;
	stack<int> cycle;
	vector<bool> onstack;

};