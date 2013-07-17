/*
ID: rajorsh2
PROG: packrec
LANG: C++
*/
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

int rect[4][2];

struct sort_pred 
{
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) 
	{
        return left.first < right.first;
    }
};

void bestof(int& best, int w, int h, vector<pair<int, int> >& ans)
{
	int area = w*h;
	if(area > best)
		return;

	pair<int, int> p = make_pair(min(w,h), max(w,h));
	if(area == best)
	{
		bool found = false;
		for(int i=0; i<ans.size(); i++)
		{
			if(ans[i] == p) 
				found = true;
		}

		if(!found)
			ans.push_back(p);
		return;
	}
	else
	{
		ans.clear();
		ans.push_back(p);
		best = area;
	}
}

void process(vector<int>& p, vector<int>& rotate, int& best, vector<pair<int, int> >& ans)
{
	int area = 0, w = 0, h = 0;

	int w1 = rect[p[0]][rotate[0]], h1 = rect[p[0]][1-rotate[0]];
	int w2 = rect[p[1]][rotate[1]], h2 = rect[p[1]][1-rotate[1]];
	int w3 = rect[p[2]][rotate[2]], h3 = rect[p[2]][1-rotate[2]];
	int w4 = rect[p[3]][rotate[3]], h4 = rect[p[3]][1-rotate[3]];
	
	// case 1
	w = w1+w2+w3+w4;
	h = max(max(h1,h2),max(h3,h4));
	bestof(best, w, h, ans);

	// case 2
	w = max(w1+w2+w3, w4);
	h = h4 + max(h1, max(h2,h3));
	bestof(best, w, h, ans);

	// case 3
	w = w4 + max(w3, w1+w2);
	h = max( h4, h3 + max(h1, h2));
	bestof(best, w, h, ans);

	// case 4
	w = w1 + max(w2,w3) + w4;
	h = max(max(h1, h4), h2+h3);
	bestof(best, w, h, ans);

	// case 5
	w = max(w1, w2) + w3 + w4;
	h = max(max(h3,h4), h1+h2);
	bestof(best, w, h, ans);

	// case 6a
	w = max(w1+w2, w3+w4);
	h = max(h1, h2) + max(h3, h4);
	bestof(best, w, h, ans);

	if(w3<=w1 && w4<=w2) h=max(h1+h3, h2+h4);
	bestof(best, w, h, ans);

	if(w4<w2 && w3+w4<=w1+w2 && h2<=h1) h=max(h1+h3, h2+h4);
	bestof(best, w, h, ans);


	// case 6b
	h = max(h1+h2, h3+h4);
	w = max(w1,w2) + max(w3,w4);
	bestof(best, w, h, ans);


}

int main() 
{
	ifstream cin("packrec.in");
	ofstream cout("packrec.out");
    
    
	for(int i=0; i<4; i++) 
	{
		for(int j=0; j<2; j++) 
		{
			cin>>rect[i][j];
		}
	}

	vector<int> p;
	for(int i=0; i<4; i++)
		p.push_back(i);

	int best = 1 << 30;
	vector<pair<int, int> > ans;

	do 
	{
		//cout<<p[0]<<", "<<p[1]<<", "<<p[2]<<", "<<p[3]<<endl;
		for(int mask = 0; mask < 16; mask++)
		{
			vector<int> rotate(4, 0);
			for(int r=0; r<4; r++)
			{
				rotate[r] = (mask & (1 << r)) ? 1 : 0;
			}
			process(p, rotate, best, ans);			
		}
	}
	while(next_permutation(p.begin(), p.end()));

	cout<<best<<endl;
	sort(ans.begin(), ans.end(), sort_pred());
	for(int i=0; i<ans.size(); i++) 
		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	return 0;
}