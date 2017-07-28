#include "Graph.h"


Graph::Graph(int V)
{
	this->V =  V;
	this->E = 0;
	adj = vector<vector<int> > (V);
// 	for(int v = 0; v< V;v++)
// 		adj[v] = new vector <int>();

}
Graph::Graph()
{
	this->V =  10;
	this->E = 0;
	adj = vector<vector<int> > (V);
	// 	for(int v = 0; v< V;v++)
	// 		adj[v] = new vector <int>();

}
Graph ::Graph(istream& In)
{
	int vTemp ;
	int eTemp;
	In >> vTemp;
	new (this)Graph( vTemp);            
    In >> eTemp;
	for (int i = 0;i < eTemp;i++)
	{
		int v;
		int w;
		In >> v;
		In >> w;
		addEdge(v,w);
	}
}
void Graph::addEdge(int v,int w)
{
	auto result1 = std::find(adj[v].cbegin(),adj[v].cend(),w);
	if (result1 == adj[v].cend())
	{
		adj[v].push_back(w);
	}
	auto result2 = std::find(adj[w].cbegin(),adj[w].cend(),w);
	if (result2 == adj[w].cend())
	{
		adj[w].push_back(v);
	}
	
	E++;
}
vector <int>Graph::getAdj(int V)
{
	return adj[V];
}
	