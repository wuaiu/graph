#include "Digraph.h"


Digraph::Digraph()
{
	this->V =  10;
	this->E = 0;
	adj = vector<vector<int> > (V);
	// 	for(int v = 0; v< V;v++)
	// 		adj[v] = new vector <int>();

}
Digraph::Digraph(int V)
{
	this->V = V;
	this->E = 0;
	adj = vector<vector<int> >(V);


}
Digraph::Digraph(istream& in)
{
	int vTemp ;
	int eTemp;
	in >> vTemp;
	new (this)Digraph( vTemp);            
	in >> eTemp;
	for (int i = 0;i < eTemp;i++)
	{
		int v;
		int w;
		in >> v;
		in>> w;
		addEdge(v,w);
	}
}
void Digraph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	E++;
}
Digraph Digraph::reverse()
{
	Digraph R (V);
	for (int v=0;v<V;v++)
	{
		vector<int> vec = adj[v];
		for (auto iter=vec.begin();iter!=vec.end();iter++)
		{
			R.addEdge(*iter,v);
		}

	}
	return R;
}