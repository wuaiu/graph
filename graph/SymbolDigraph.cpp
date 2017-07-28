#include "SymbolDigraph.h"
#include <iostream>
#include <fstream>
#include<sstream>
using  std::ofstream;
using  std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;


SymbolDigraph::SymbolDigraph(string stream,string sp)

{
	//int tempX[]= {0,6,1,5,2,3,4,9,7,8,12,10,11};

	st   = BinarySearchST<string,int>();
	ifstream in (stream);
	string line;
	int m = 0;
	while(getline(in,line))
	{
		m++;

		vector<string> vec;
		string word;
		while(1)                
		{               
			int pos = line.find('/');
			if( pos==0)
			{       
				line=line.substr(1);
				continue;
			}       
			if( pos < 0)
			{
				vec.push_back(line);
				break;
			}       
			word = line.substr(0,pos);
			line = line.substr(pos+1);
			vec.push_back(word);
		}
		for (size_t i = 0;i <vec.size();i++)
		{
			if (!st.contains(vec[i]))
			{
				st.put(vec[i],st.size()); 
				//st.put(vec[i],tempX[i]); 
			}
		}
	}
	keys = vector<string>(st.size());
	vector<string>  vecTemp = (*(st.getKeys()) );
	for (size_t i = 0;i<vecTemp.size();i++)
	{
		keys[st.get(vecTemp[i])] = vecTemp[i];
	}

	G = Digraph(st.size());
	in = ifstream(stream);
	while(getline(in,line))
	{

		vector<string> vec;
		string word;
		while(1)                
		{               
			int pos = line.find('/');
			if( pos==0)
			{       
				line=line.substr(1);
				continue;
			}       
			if( pos < 0)
			{
				vec.push_back(line);
				break;
			}       
			word = line.substr(0,pos);
			line = line.substr(pos+1);
			vec.push_back(word);
		}
		int x = st.get(vec[0]);
		for (size_t i = 1;i <vec.size();i++)
		{
			G.addEdge(x,st.get(vec[i]));
		}
	}


}
