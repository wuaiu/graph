#include "EdgeWeightGraph.h"

EdgeWeightGraph::EdgeWeightGraph(int V)
{
	this->V = V;
	this->E = 0;
	adj = vector<vector <Edge> > (V);//需要合适的默认构造函数；
}
EdgeWeightGraph::EdgeWeightGraph(istream& in)
{
	int vTemp ;
	int eTemp;
	double weightTemp;
	in >> vTemp;
	new (this)EdgeWeightGraph( vTemp);            
	in >> eTemp;
	
	for (int i = 0;i < eTemp;i++)
	{
		int v;
		int w;
		in >> v;
		in >> w;
		in >> weightTemp;
		Edge e (v,w,weightTemp);
		addEdge(e);
	}
	
}
void EdgeWeightGraph::addEdge(Edge e)
{
	int v = e.either();
	int w = e.other(v);
	adj[v].push_back(e);
	adj[w].push_back(e);
	E++;
}
vector<Edge> EdgeWeightGraph::edges()
{
	vector<Edge> b ;
	for (int v=0;v<V;v++)
	{
		vector<Edge> vec = adj[v];
		for (auto iter=vec.begin();iter!=vec.end();iter++)
		{
			if ((*iter).other(v) >v)
			{
				b.push_back(*iter);
			}
		}
	}
	return b;
}