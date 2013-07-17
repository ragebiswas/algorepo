/*
 * graph_test.cc
 *
 *  Created on: Apr 9, 2011
 *      Author: biswasra
 */

#include <iostream>
#include <string>

#include "graph.hh"

using namespace std;

void graph_test_run()
{
	graph<int> g(5);

	int edges[] =
	{ 1, 2, 1, 3, 2, 4, 3, 5 };
	//{ 1, 2, 2, 3, 1, 3, 2, 4, 3, 5 };

	for (int i = 0; i < 8; i = i + 2)
	{
		g.insert(edges[i], edges[i + 1]);
	}

	cout << "*** print: " << endl;
	g.print_graph();
	cout << endl;

	cout << "*** DFS(1): " << endl;
	g.reset_visited();
	g.dfs(1);
	cout << endl;

	cout << "*** DFS(5): " << endl;
	g.reset_visited();
	g.dfs(5);
	cout << endl;

	cout << "*** BFS(1): " << endl;
	g.reset_visited();
	g.bfs(1);
	cout << endl;

	cout << "*** BFS(2): " << endl;
	g.reset_visited();
	g.bfs(2);
	cout << endl;

	cout << "*** delete 2 edges: " << endl;
	g.remove(4, 2);
	g.remove(2, 1);
	g.print_graph();

	cout << "*** has_edge (1,2): " << g.has_edge(1, 2) << endl;
	cout << "*** has_edge (2,1): " << g.has_edge(2, 1) << endl;
	cout << "*** has_edge (3,1): " << g.has_edge(3, 1) << endl;

}
