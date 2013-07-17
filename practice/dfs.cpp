#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

enum color_t { WHITE, GRAY, BLACK };

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
	
	void dfs(int n)
	{
		for(int i=1; i<=numnodes; i++)
		{
			nodes[i].color = WHITE;
		}
		
		for(int i=1; i<=numnodes; i++)
		{
			if(nodes[i].color == WHITE)
				dfs_visit(i);
			cout<<"-----\n";
		}
	}
	
	void dfs_visit(int n)
	{
		nodes[n].color = GRAY;
		cout<<"Visited: "<<n<<endl;

		vector<edge> adjlist = adjlists[n];
		for(int i=0; i<adjlist.size(); i++)
		{
			int v2 = adjlist[i].v2;
			if(nodes[v2].color == WHITE)
				dfs_visit(v2);
		}
		nodes[n].color = BLACK;
	}
	
	
};

int main()
{
	Graph g(5);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(4,2);
	g.add_edge(5,1);
	g.dfs(1);
	return 0;
}