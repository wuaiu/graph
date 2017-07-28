#pragma once
#include "..\ST\BinarySearchST.h"
#include "Graph.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class SymbolGraph
{
public:
	SymbolGraph(string stream,string sp);
	//bool contains(string s){return st.contain(s);}
	int index(string s)
	{
		return st.get(s);
	}
	string name(int v){return keys[v];}
	Graph getG() {return G;}
private:
	
	vector<string> keys;
	Graph G;

	BinarySearchST<string,int> st;
};