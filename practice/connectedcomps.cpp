#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

enum color_t { WHITE, GRAY, BLACK };

void print(int i)
{
	cout<<i<<" ";
}

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
	color_t color;
	
	node()
	{
		visited = false;
		data = 0;
		color = WHITE;
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
	
	void connected_components(vector<vector<int> >& result)
	{
		// DFS from node 1
		for(int i=1; i<=numnodes; i++)
		{
			nodes[i].color = WHITE;
		}
		
		for(int i=1; i<=numnodes; i++)
		{
			vector<int> v;
			if(nodes[i].color == WHITE)
				dfs_visit(i, v);
			if(!v.empty())
				result.push_back(v);
		}
	}
	
	void dfs_visit(int n, vector<int>& v)
	{
		nodes[n].color = GRAY;
		v.push_back(n);

		vector<edge> adjlist = adjlists[n];
		for(int i=0; i<adjlist.size(); i++)
		{
			int v2 = adjlist[i].v2;
			if(nodes[v2].color == WHITE)
				dfs_visit(v2, v);
		}
		nodes[n].color = BLACK;
	}
	
	
};

int main()
{
	Graph g(5);
	g.add_edge(1,2);
	g.add_edge(2,1);
	g.add_edge(2,3);
	g.add_edge(3,2);	
	g.add_edge(4,5);
	g.add_edge(5,4);
	
	vector<vector<int> > components;
	g.connected_components(components);
	
	for(int i = 0; i<components.size(); i++)
	{
		cout<<"Connected component "<<i+1<<": ";
		for_each(components[i].begin(), components[i].end(), print);
		cout<<endl;
	}
	
	return 0;
}