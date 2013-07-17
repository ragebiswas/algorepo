/*
 * graph.hh
 * 		Base graph DS
 *
 *  Created on: Apr 9, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

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

public:

	graph(int n)
	{
		assert(n > 0 && n < 100);
		numnodes = n;

		// 1 based (0th elements are dummies)
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

	void print_graph()
	{
		for (int v = 1; v <= numnodes; ++v)
		{
			cout << "Node " << v << ": ";
			vector<int>::iterator it = adjlists[v].begin();
			while (it != adjlists[v].end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}
	}

	void remove(int v, int w)
	{
		assert( v <= numnodes && w <= numnodes && w != v);

		vector<int>::iterator it;

		vector<int>& vlist = adjlists[v];
		vector<int>& wlist = adjlists[w];

		// delete w from vlist
		it = find(vlist.begin(), vlist.end(), w);
		if (it != vlist.end())
		{
			vlist.erase(it);
		}

		// delete v from wlist
		it = find(wlist.begin(), wlist.end(), v);
		if (it != wlist.end())
		{
			wlist.erase(it);
		}
	}

	bool has_edge(int v, int w)
	{
		vector<int>& vlist = adjlists[v];
		return find(vlist.begin(), vlist.end(), w) != vlist.end();
	}

	void reset_visited()
	{
		for (int i = 1; i <= numnodes; ++i)
		{
			nodes[i].visited = false;
			nodes[i].discovered = false;
		}
	}

	void visit(int v)
	{
		cout << "Visited: " << v << endl;
	}

	void dfs(int n = 1)
	{
		nodes[n].visited = true;
		visit(n);

		for (size_t i = 0; i < adjlists[n].size(); ++i)
		{
			int w = adjlists[n][i];
			if (nodes[w].visited == false)
			{
				dfs(w);
			}
		}
	}

	void bfs(int n = 1)
	{
		queue<int> bfs_queue;
		bfs_queue.push(n);

		while (!bfs_queue.empty())
		{
			int v = bfs_queue.front();
			bfs_queue.pop();

			visit(v);

			for (size_t i = 0; i < adjlists[v].size(); ++i)
			{
				int w = adjlists[v][i];

				if (nodes[w].visited == false && nodes[w].discovered == false)
				{
					nodes[w].discovered = true;
					bfs_queue.push(w);
				}
			}

			nodes[v].visited = true;

		}
	}

};
