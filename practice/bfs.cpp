#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

struct edge
{
	int v1; 
	int v2;
	int wt;
	
	edge(int v1, int v2, int wt = 0)
	{	
		this->v1 = v1;
		this->v2 = v2;
		this->wt = wt;
	}
};

struct node
{
	bool visited;
	int data;
	
	node()
	{
		visited = false;
		data = 0;
	}
};

class Graph
{
private:
	int numnodes;
	vector<vector<edge> > adjlists;
	vector<node> nodes;
	
public:
	Graph(int numnodes)
	{
		this->numnodes = numnodes;
		vector<edge> v;
		node n;
		for(int i=0; i<=numnodes; i++)
		{
			nodes.push_back(n);
			adjlists.push_back(v);
		}
	}
	
	void add_edge(int v1, int v2, int wt = 0)
	{
		edge e(v1, v2, wt);
		adjlists[v1].push_back(e);
	}
	
	void bfs(int s)
	{
		assert(s <= numnodes);
		queue<int> q;
		q.push(s);
		
		while(!q.empty())
		{
			int n = q.front();
			q.pop();
			cout<<"Visited: "<<n<<endl;
			nodes[n].visited = true;			
						
			vector<edge> adjlist = adjlists[n];
			for(size_t i=0; i<adjlist.size(); i++)
			{
				int k = adjlist[i].v2;
				if(!nodes[k].visited)
				{	
					nodes[k].visited = true;
					q.push(k);
				}
			}

		}
	}
};

int main()
{
	Graph g(5);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(4,2);
	g.add_edge(1,5);
	g.bfs(1);
	return 0;
}