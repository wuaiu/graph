#pragma once
#include <vector>
#include <iostream>

using std::istream;
using std::ifstream;
using std::vector;
#include<algorithm>
#include "Digraph.h"
#include "DirectedCycle.h"
#include "DepthFirstOrder.h"
class Topological
{
public:
	Topological(Digraph G);
	stack<int> getOrder(){return order;}
	bool isDAG(){return order.size() != 0;}
private:
	stack<int> order;
};