#include "PrimMST.h"


PrimMST::PrimMST(EdgeWeightGraph G)
{
	edgeTo = vector<Edge> (G.getV());
	distTo = vector<double>(G.getV());
	marked = vector<bool> (G.getV());
	for (int v=0;v<G.getV();v++)
	{
		distTo[v] = 999999;
	}
	//pq = priority_queue<double> (G.getV());
	distTo[0]=0.0;
	//pq.push(0.0);
	m_map.insert(make_pair(0.0,0));
	m_set.insert(0);
	while (!m_map.empty())
	{
		auto iter =m_map.begin();
		int w = iter->second;
		visit(G,w);
		//pq.pop();

		m_map.erase(iter);
	}

}
void PrimMST::visit(EdgeWeightGraph G,int v)
{
	marked[v] = true;
	vector<Edge> vec= G.getAdj(v);
	for (auto iter=vec.begin();iter!=vec.end();iter++)
	{
		int w =(*iter).other(v);
		if (marked[w])
		{
			continue;
		}
		if ((*iter).getWeight() < distTo[w])
		{
			edgeTo[w] = (*iter);
			distTo[w] = (*iter).getWeight();

			//m_map[w]=distTo[w];
			if (m_set.find(w)!=m_set.end())
			{
			for (auto iter = m_map.begin();iter!=m_map.end();iter++)
			{
				if((iter->second) == w)
				{
					m_map.erase(iter);
					m_map.insert(make_pair(distTo[w],w));
					break;
				}
			}
			}
                   
			
			else
			{
			   m_set.insert(w);
			   m_map.insert(make_pair(distTo[w],w));
			}
		}
	}
}
vector<Edge>PrimMST::edges()
{
	vector<Edge> mst;
	for (int v=1;v<edgeTo.size();v++)
	{
		mst.push_back(edgeTo[v]);
	}
	return mst;
}

