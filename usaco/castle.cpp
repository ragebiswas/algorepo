/*
ID: rajorsh2
PROG: castle
LANG: C++
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int r, c;
int arr[50][50];
bool vis[50][50];
const int W = 1, N = 2, E = 4, S = 8;

void reset()
{
	for (int i = 0; i < 50; i++)
	for (int j = 0; j < 50; j++)
		vis[i][j] = false;
}

int fill(int i, int j)
{
	if ((i < 0) || (i >= r) || (j < 0) || (j >= c))
		return 0;

	if (vis[i][j])
		return 0;

	int nr = 1, val = arr[i][j];
	vis[i][j] = 1;
	//cout << "Visited :" << i + 1 << ',' << j + 1 << endl;

	if (!(val & W)) {
		nr += fill(i, j - 1);
	}
	if (!(val & N)) {
		nr += fill(i - 1, j);
	}
	if (!(val & E)) {
		nr += fill(i, j + 1);
	}
	if (!(val & S)) {
		nr += fill(i + 1, j);
	}
	return nr;
}

void getlargest(int& largest, int& numrooms)
{
	largest = 0;
	numrooms = 0;
	reset();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vis[i][j] != true) {
				int cur = fill(i, j);
				largest = max(cur, largest);
				numrooms++;
			}
		}
	}
}

void check(int& largest, int& cur, int& ansx, int& ansy, int& curx, int& cury, char& dir, char curdir)
{
	if (cur > largest) {
        //cout << "poss: " << cur << " at " << curx << ", " << cury << ", " << curdir << endl;
		largest = cur;
		ansx = curx;
		ansy = cury;
		dir = curdir;
	}
}

void solve(int& finalsz, int& finalx, int& finaly, char& finaldir)
{
	int largest = 0, numrooms = 0, l, n;
	int ansx, ansy;
	char dir;

    for (int j = 0; j < c; j++) {
        for (int i = r - 1; i >= 0; i--) {
		
			int val = arr[i][j], val2;
			if (val & W) {
				arr[i][j] &= ~W;
				if (j > 0) {
					val2 = arr[i][j - 1];
					arr[i][j - 1] &= ~E;
				}
				getlargest(l, n);
				check(largest, l, ansx, ansy, i, j, dir, 'W');
				arr[i][j] = val;
				if (j > 0) {
					arr[i][j - 1] = val2;
				}
			}
			if (val & N) {
				arr[i][j] &= ~N;
				if (i > 0) {
					val2 = arr[i - 1][j];
					arr[i - 1][j] &= ~S;
				}
				getlargest(l, n);
				check(largest, l, ansx, ansy, i, j, dir, 'N');
				arr[i][j] = val;
				if (i > 0) {
					arr[i - 1][j] = val2;
				}
			}
			if (val & E) {
				arr[i][j] &= ~E;
				if (j < c - 1) {
					val2 = arr[i][j + 1];
					arr[i][j + 1] &= ~W;
				}
				getlargest(l, n);
				check(largest, l, ansx, ansy, i, j, dir, 'E');
				arr[i][j] = val;
				if (j < c - 1){
					arr[i][j + 1] = val2;
				}
			}
			if (val & S) {
				arr[i][j] &= ~S;
				if (i < r - 1) {
					val2 = arr[i + 1][j];
					arr[i + 1][j] &= ~N;
				}
				getlargest(l, n);
				check(largest, l, ansx, ansy, i, j, dir, 'S');
				arr[i][j] = val;
				if (i < r - 1) {
					arr[i + 1][j] = val2;
				}
			}
		}
	}
    
	finalsz = largest;
    finalx = ansx + 1;
    finaly = ansy + 1;
    finaldir = dir;
}

int main()
{
	ifstream cin("castle.in");
    ofstream cout("castle.out");
	int i, j, x, y;
    char dir; 
    
	cin >> c >> r;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	// Number of rooms and size of largest	
	int largest, numrooms;
	getlargest(largest, numrooms);

	cout << numrooms << endl;
	cout << largest << endl;

	// Remove each wall and try
	solve(largest, x, y, dir);
    cout << largest << endl;
    cout << x << " " << y << " " << dir << endl;
	return 0;
}