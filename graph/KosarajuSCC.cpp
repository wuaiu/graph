#include "KosarajuSCC.h"
KosarajuSCC::KosarajuSCC(Digraph G)
{
	count = 0;
	marked = vector<bool>(G.getV());
	id = vector<int> (G.getV());
	DepthFirstOrder order (G.reverse());
	stack <int> sta= order.getReversePost();
	
	while (!sta.empty())
	{
		int w = sta.top();
		if (!marked[w])
		{
			dfs(G,w);
			count++;
		}
		sta.pop();

	}
}
void KosarajuSCC::dfs(Digraph G,int v)
{
	marked[v] = true;
	id[v] = count;
	vector<int> vec = G.getAdj(v);
	for (auto iter = vec.begin();iter!=vec.end();iter++)
	{
		if (!marked[*iter])
		{
			dfs(G,*iter);
		}
		
	}
}


//#include "Gragh/Graph.h"
//#include "Gragh\SymbolGraph.h"
//#include "Gragh\DirectedDFS.h"
//#include "Gragh\Digraph.h"
//#include "Gragh\Topoligical.h"
//#include "Gragh\SymbolDigraph.h"
//#include "Gragh\KosarajuSCC.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include<stack>
//using std::stack;
//
//using std::string;
//using  std::ofstream;
//using  std::ifstream;
//using std::vector;
//ifstream in("tinyDG.txt");
//ofstream out("2.txt");
//
//
//int main()
//{
//
//	Digraph G (in);
//	KosarajuSCC scc(G);
//	int M = scc.getCount();
//	out<<M <<"components"<<std::endl;
//	vector<vector<int> >components(M);
//	for (int v = 0;v<G.getV();v++)
//	{
//		components[scc.getId(v)].push_back(v);
//	}
//	for (int i = 0;i<M;i++)
//	{
//		vector<int> vec = components[i];
//		for (auto iter = vec.begin();iter!=vec.end();iter++)
//		{
//			out << (*iter)<<"  ";
//		}
//		out <<std::endl;
//	}
//
//
//}
