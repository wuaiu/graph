#pragma  once
#include <iostream>
#include<vector>
using std::istream;
using std::ifstream;
using std::vector;
#include<algorithm>



class Graph
{
public:
	Graph (int V);
	Graph ();
	Graph(istream& In);
	int getV() {return V;}
	int getE() {return E;}
	void addEdge(int v,int w);
	vector<int> getAdj(int V);
private:
	int V;
	int E;
	vector<vector<int> > adj;
};