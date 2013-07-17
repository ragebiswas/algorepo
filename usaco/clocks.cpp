/*
ID: rajorsh2
PROG: clocks
LANG: C++
*/
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <hash_map>
#include <string>
#include <sstream>

using namespace std;
using namespace __gnu_cxx;

vector<int> ans;
const int zs[] = { 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
const int ten9 = 1000000000;
const string config[] = { "ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI" };
int nobj=0;

struct state
{
	int clocks; // 1abcdefghi
	int prevop;
	state* prevstate;
	
	state()
	{
		clocks = ten9;
	}

	int getclock(int idx)
	{
		int t = clocks - ten9;
		return (t/zs[idx]) % 10;
	}

	void setclock(int idx, int val)
	{
		int c = getclock(idx)*zs[idx];
		clocks -= c;
		clocks += val*zs[idx];
	}

	void inc(const string& str)
	{
		for(int i=0; i<str.size(); i++)
		{
			int idx = str[i]-'A';
			int val = getclock(idx);
			val += 3;
			val %= 12;
			setclock(idx, val);
		}
	}
	bool equals(state* astate)
	{
		return (this->clocks == astate->clocks);
	}

	void set(state* astate)
	{
		this->clocks = astate->clocks;
	}
	void set(int clocks)
	{
		this->clocks = ten9+clocks;
	}
};

vector<vector<int> > answers;
hash_map<int, bool> visited;
queue<state*> bfsq;
state* istate = NULL;

bool print(state* astate)
{	
	while(!astate->equals(istate))
	{
		ans.push_back(astate->prevop);
		astate = astate->prevstate;
	}

	return false;
}

state newstate;
bool process(state* astate, queue<state*>& bfsq)
{
	if(astate->clocks == ten9)
	{
		return print(astate);
	}
	
	for(int i=0; i<9; i++)
	{
		newstate.set(astate);
		newstate.inc(config[i]);
		//cout<<"trying state: "<<newstates[i].getnum()<<", foundsz="<<answers.size()<<endl;

		if(visited.find(newstate.clocks) == visited.end())
		{
			state *ns = new state();
			ns->clocks = newstate.clocks;
			ns->prevop = i+1;
		    ns->prevstate = astate;
			bfsq.push(ns);
			visited[ns->clocks] = true;
			nobj++;
		}
	}
	return true;
}

void search()
{
	bfsq.push(istate);
	visited[istate->clocks] = true;

	while(!bfsq.empty())
	{
		state *astate = bfsq.front();
		bfsq.pop();
		if(process(astate, bfsq) == false)
			return;
	}
}


int main() 
{
	ifstream cin("clocks.in");
	ofstream cout("clocks.out");

	string s = "         ";
	int t;
	for(int i=0; i<9; i++)
	{
		int tmp;
		cin>>tmp;
		tmp %= 12;
		s[i] = tmp+'0';
	}
	istringstream iss(s);
	iss>>t;
	istate = new state;
	istate->set(t);

	istate->prevop = -1;
	istate->prevstate = NULL;
	search();

	sort(ans.begin(), ans.end());
	for(int j=0; j<ans.size()-1; j++) 
		cout<<ans[j]<<' '; 
	cout<<ans[ans.size()-1];
	cout<<endl;
	
	//cout<<"size of map:"<<visited.size()<<endl;
	//cout<<"size of queue:"<<bfsq.size()<<endl;
    //cout<<"no of state objects:"<<nobj<<endl;

	//system("pause");
	return 0;
}