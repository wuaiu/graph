#pragma once
#include <vector>
#include <iostream>
using std::istream;
using std::ifstream;
using std::vector;
#include<algorithm>
class Digraph
{
public:
	Digraph();
	Digraph(int V);
	Digraph(istream& in);
	int getV(){return V;}
	int getE(){return E;}
	void addEdge(int v,int w);
	vector<int> getAdj(int v) {return adj[v];}
	Digraph reverse();

private:
	int V;
	int E;
	vector<vector<int> >adj;
		
};