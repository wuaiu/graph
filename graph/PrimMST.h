#pragma once
#include <vector>
#include <iostream>
#include "EdgeWeightGraph.h"
#include <queue> 
#include <deque>
#include<algorithm>
#include <map>
#include <set>
using std::make_pair;
using std:: priority_queue;
using std::istream;
using std::ifstream;
using std::vector;
using std::deque;
//using std::greater;
using std::map;
using std::set;
class PrimMST
{
public:
	PrimMST(EdgeWeightGraph G);
	vector<Edge> edges();
	//double Weight();
	
private:
	void visit(EdgeWeightGraph G,int v);

	vector<Edge> edgeTo;
	vector<double> distTo;
	vector<bool>  marked;
	//priority_queue<double> pq;
	//priority_queue<deque<int>, greater<int>> pq;
	map<double,int>    m_map;
	set<int>     m_set;


};