#pragma once
#include <vector>
#include <iostream>
#include "Edge.h"
using std::istream;
using std::ifstream;
using std::vector;


class EdgeWeightGraph
{
public:
	EdgeWeightGraph(int V);
	EdgeWeightGraph(istream& in);
	int getV(){return V;}
	int getE(){return E;}
	void addEdge(Edge e);
	vector<Edge>  getAdj(int v){return adj[v];}
	vector<Edge> edges();
private:
	int V;
	int	E;
	vector<vector<Edge> >adj;

};