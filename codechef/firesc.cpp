#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/*
* node/vertex class
*/
template<class T>
struct node
{
	// node number
	int v;

	// obvious
	bool visited;

	// discovered, but not visited completely
	bool discovered;

	// data
	T val;

	node(int _v)
	{
		v = _v;
		visited = false;
		discovered = false;
		val = 0;
	}
};

/*
* Actual graph
*/
template<class T>
class graph
{

private:

	// the actual nodes
	vector<node<T> > nodes;

	// adjlists[n] is adjacency list for node n
	vector<vector<int> > adjlists;

	// total number of nodes
	int numnodes;

	// number of vertices in current component
	int tc;

public:

	graph(int n)
	{
		numnodes = n;
		tc = 0;

		for (int i = 0; i <= numnodes; ++i)
		{
			vector<int> adjlist;
			node<T> node(i);
			adjlists.push_back(adjlist);
			nodes.push_back(node);
		}
	}

	void insert(int v, int w)
	{
		adjlists[v].push_back(w);
		adjlists[w].push_back(v);
	}

	void dfs()
	{
		int cc = 0;
		long long ans2 = 1;
		for(int i=0; i<numnodes; i++)
		{
			if(nodes[i].visited == false)
			{
				cc++;
				if(tc!= 0)
					ans2 = ans2*tc%1000000007;
				tc = 0;
				dfsvisit(i);
			}

		}
		if(tc!=0) ans2 = ans2*tc%1000000007;
		cout<<cc<<" "<<ans2<<endl;
	}

	void dfsvisit(int n)
	{
		nodes[n].visited = true;
		tc++;

		for (size_t i = 0; i < adjlists[n].size(); ++i)
		{
			int w = adjlists[n][i];
			if (nodes[w].visited == false)
			{
				dfsvisit(w);
			}
		}
	}


};


int main()
{
	int ncases, n, m;
	int e1, e2;
	cin>>ncases;

	while(ncases--)
	{
		cin>>n>>m;
		graph<int> g(n);
		for(int i=0; i<m; i++)
		{
			cin>>e1>>e2;
			g.insert(e1-1, e2-1);
		}
		g.dfs();
	}

	return 0;
}