#include "DirectedDFS.h"

DirectedDFS::DirectedDFS(Digraph G,int s)
{
	marked = vector<bool>(G.getV());
	dfs(G,s);
}
DirectedDFS::DirectedDFS(Digraph G,vector<int> sources)
{
	marked = vector<bool>(G.getV());
	for (auto iter = sources.begin();iter!= sources.end();iter++)
	{
		if (!isMarked(*iter))
		{
			dfs(G,*iter);
		}
	}
}
void DirectedDFS::dfs(Digraph G,int v)
{
	marked[v] = true;
	vector<int> vec = G.getAdj(v);
	for (auto iter = vec.begin();iter!=vec.end();iter++ )
	{
		if (!isMarked(*iter))
		{
			dfs(G,*iter);
		}
	}
}


//#include "Gragh/Gragh.h"
//#include "Gragh\SymbolGragh.h"
//#include "Gragh\DirectedDFS.h"
//#include "Gragh\Digraph.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
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
//	Digraph G(in);
//	vector<int> sources ;
//	sources.push_back(1);
//	sources.push_back(2);
//	sources.push_back(6);
//	DirectedDFS reachable(G,sources);
//
//	for (int v = 0;v < G.getV();v++)
//	{
//		if (reachable.isMarked(v))
//		{
//			out << v <<" ";
//
//		}
//	}
//	out << std::endl;
//}
