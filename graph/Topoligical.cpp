#include "Topoligical.h"
Topological::Topological(Digraph G)
{
	DirectedCycle cyclefinder (G);
	if (!cyclefinder.hasCycle())
	{
		DepthFirstOrder dfs (G);
		order  = dfs.getReversePost();
	}
}



//#include "Gragh/Graph.h"
//#include "Gragh\SymbolGraph.h"
//#include "Gragh\DirectedDFS.h"
//#include "Gragh\Digraph.h"
//#include "Gragh\Topoligical.h"
//#include "Gragh\SymbolDigraph.h"
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
//	string filename1("jobs.txt");
//	string separator("/");
//	SymbolDigraph sg (filename1,separator);
//	Topological top (sg.getG());
//	stack<int> sta = top.getOrder();
//	while (!sta.empty())
//	{
//		int w = sta.top();
//		out  <<sg.name(w)<<std::endl;
//		sta.pop();
//
//	}
//
//
//}
