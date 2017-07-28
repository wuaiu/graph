#pragma once
#include <vector>
#include <iostream>
#include <stack>
#include <fstream>
#include "Digraph.h"
#include "DepthFirstOrder.h"
using std::istream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;
//ofstream out("2.txt");

class KosarajuSCC
{
public:
	KosarajuSCC(Digraph G);
	bool stronglyConnected(int v,int w){return id[v]==id[w];}
	int getId(int v){return id[v];}
	int getCount(){return count;}

private:
	    void dfs(Digraph G,int v);
		vector<bool>  marked;
		vector<int> id;
		int count;
};