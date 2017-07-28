#pragma once
#include <vector>
#include <iostream>
#include<queue>
#include <stack>
#include "Digraph.h"
using std::istream;
using std::ifstream;
using std::vector;
using std::queue;
using std::stack;
#include<algorithm>
class DepthFirstOrder
{
public:
	DepthFirstOrder(Digraph G);
	queue<int> getPre(){return pre;}
	queue<int> getPost(){return post;}
	stack<int> getReversePost(){return reversePost;}
private:
	void dfs(Digraph G,int v);
	vector<bool> marked;
	queue<int>  pre;
	queue<int>  post;
	stack <int> reversePost;
		
};