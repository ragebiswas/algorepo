#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

#define LEN 50000
#define INPUT "C-small-attempt0.in"

static void print(string i)
{
  cout<<i<<endl;
}

static string readline(ifstream& ifs)
{
  char line[LEN];
  ifs.getline(line, LEN);
  string s = line;
  return s;
}

static string int_to_string(long i)
{
	ostringstream oss;
	oss<<i;
	return oss.str();
}

static long string_to_int(string s)
{
	istringstream iss(s);
	int i;
	iss>>i;
	return i;
}


int padd(int a, int b)
{
	return a^b;
}


string solve(vector<int> candies)
{
	int maxscore = 0;

	int sz = candies.size();

	for(int i=0; i< (1<<sz); i++)
	{
		vector<int> sc; // sean's candies
		vector<int> pc; // patrick's candies

		for(int j=0; j<sz; j++)
		{
			if(i & (1<<j))
				sc.push_back(candies[j]);
			else
				pc.push_back(candies[j]);
		}

		int ssum = accumulate(sc.begin(), sc.end(), 0);
		int p1sum = accumulate(pc.begin(), pc.end(), 0, padd);
		int p2sum = accumulate(sc.begin(), sc.end(), 0, padd);

		if(p1sum == p2sum && !pc.empty() && !sc.empty()) 
		{
			if(ssum > maxscore)
				maxscore = ssum;
		}

	}


	if(maxscore > 0)
		return int_to_string(maxscore);
	else
		return "NO";
}



int main()
{
  ifstream ifs;
  ifs.open(INPUT);

  int ncases = 0;
  string ncases_str = readline(ifs);
  istringstream iss(ncases_str);
  iss>>ncases;
  
  for(int nc=0; nc<ncases; nc++)
  {
	  int ncandies = 0;
	  string ncandies_str = readline(ifs);
	  istringstream iss(ncandies_str);
	  iss>>ncandies;
	  
	  vector<int> candies;
	  string candies_str = readline(ifs);
	  istringstream iss2(candies_str);
	  
	  for(int j=0; j<ncandies; j++)
	  {
		  int c;
		  iss2>>c;
		  candies.push_back(c);
	  }

	  cout<<"Case #"<<nc+1<<": "<<solve(candies)<<endl;
  }

  return 0;

}

