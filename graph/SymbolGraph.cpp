#include "SymbolGraph.h"
#include <iostream>
#include <fstream>
#include<sstream>
using  std::ofstream;
using  std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;


SymbolGraph::SymbolGraph(string stream,string sp)

{

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
			}
		}
	}
	keys = vector<string>(st.size());
	vector<string>  vecTemp = (*(st.getKeys()) );
	for (size_t i = 0;i<vecTemp.size();i++)
	{
		keys[st.get(vecTemp[i])] = vecTemp[i];
	}

	G =Graph(st.size());
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

	
	
//#include "Gragh/Gragh.h"
//#include "Gragh\SymbolGragh.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using std::string;
//using  std::ofstream;
//using  std::ifstream;
//using std::vector;
//ifstream in("1.txt");
//ofstream out("2.txt");
//
//
//int main()
//{
//
//	string filename("movies1.txt");
//	string deflim = "/";
//	SymbolGraph sg (filename,deflim );
//	Gragh G = sg.getG();
//	string source;
//	while(getline(in,source))
//	{
//		out << source << ":" << std::endl;
//		int m1 = sg.index(source);          //vals[i]
//		vector <int> vTemp = G.getAdj(m1);
//		for(size_t i = 0;i < vTemp.size();i++)
//		{
//			int w =  vTemp[i];
//			out << "   " << sg.name(w);
//			out <<std::endl;
//		}
//
//	}
//}
