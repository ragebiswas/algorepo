#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

struct tree {
	int x, y, z;
};

int getdist(tree& t1, tree& t2)
{
	long long d = ((t1.x - t2.x) * (t1.x - t2.x)) + 
			((t1.y - t2.y) * (t1.y - t2.y)) + 
			((t1.z - t2.z) * (t1.z - t2.z));
	double root = sqrt(d * 1.0);
	return int(floor(root));
}

int main()
{
	vector<tree> trees;
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) {
			break;
		}
		tree t;
		t.x = x;
		t.y = y;
		t.z = z;
		trees.push_back(t);
	}

	vector<int> counts(10, 0);
	for(int i = 0; i < trees.size(); i++) {		
		int nearest = 999999999;
		for(int j = 0; j < trees.size(); j++) {
			if (i != j) {
				int dist = getdist(trees[i], trees[j]);
				if (dist < nearest) {
					nearest = dist;
				}
			}
		}
		if (nearest < 10) {
			counts[nearest]++;
		}
	}

	for(int i = 0; i < 10; i++) {
		printf("%4d", counts[i]);
	}
	printf("\n");

	return 0;
}