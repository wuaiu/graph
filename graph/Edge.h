#pragma once
#include <vector>
#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::vector;
class Edge
{
public:
	Edge();
	Edge(int v,int w,double weight);
	double getWeight(){return weight;}
	int either(){return v;}
	int other(int vertex)
	{
		if (vertex == v)
		{
			return w;
		} 
		else if(vertex == w)
		{
			return v;
		}
	}
	int compareTo(Edge* that)
	{
		if (this->getWeight()<that->getWeight())
		{
			return -1;
		}
		else if (this->getWeight()>that->getWeight())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
private:
	int v;
	int w;
	double weight;
};

