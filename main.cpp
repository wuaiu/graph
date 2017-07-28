#include "graph/Graph.h"
#include "graph/SymbolGraph.h"
#include "graph/DirectedDFS.h"
#include "graph/Digraph.h"
#include "graph/Topoligical.h"
#include "graph/SymbolDigraph.h"
#include "graph/KosarajuSCC.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<stack>
using std::string;
using  std::ofstream;
using  std::ifstream;
using std::vector;
ifstream in("tinyDG.txt");
ofstream out("output.txt");


int main()
{

	Digraph G(in);
	KosarajuSCC scc(G);
	int M = scc.getCount();
	out << M << "components" << std::endl;
	vector<vector<int> >components(M);
	for (int v = 0; v < G.getV(); v++)
	{
		components[scc.getId(v)].push_back(v);
	}
	for (int i = 0; i < M; i++)
	{
		vector<int> vec = components[i];
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			out << (*iter) << "  ";
		}
		out << std::endl;
	}


}