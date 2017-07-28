#pragma once
#include "..\ST\BinarySearchST.h"
#include "Digraph.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

class SymbolDigraph
{
public:
	SymbolDigraph(string stream,string sp);
	//bool contains(string s){return st.contain(s);}
	int index(string s)
	{
		return st.get(s);
	}
	string name(int v){return keys[v];}
	Digraph getG() {return G;}
private:

	vector<string> keys;
	Digraph G;

	BinarySearchST<string,int> st;
};