// ---------------------------------------------------------------------------
// findwords.cc - solution to http://www.gild.com/compete/competitions/193
// author: Rajorshi Biswas <rajorshi.biswas@gmail.com>
// ---------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<bool> > solve(const vector<string>& grid, map<size_t, vector<string> >& wmap)
{
	size_t rows = grid.size();
	size_t cols = grid[0].size();

	vector<bool> bits(cols, false);
	vector<vector<bool> > bitset(rows, bits);

	// left to right and right to left cases
	for(size_t r = 0; r < rows; r++)
	{
		for(size_t c1 = 0; c1 < cols; c1++)
		{
			for(size_t c2 = c1; c2 < cols; c2++)
			{
				string key = grid[r].substr(c1, (c2-c1)+1);

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(size_t c = c1; c <= c2; c++)
						bitset[r][c] = true;

					//cout<<"LTR/RTL: "<<key<<endl;
				}
			}
		}
	}



	// top to bottom and bottom to top case
	for(size_t c = 0; c < cols; c++)
	{
		for(size_t r1 = 0; r1 < rows; r1++)
		{
			// form the word
			string key = "";

			for(size_t r2 = r1; r2 < rows; r2++)
			{
				key += grid[r2][c];

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(size_t r = r1; r <= r2; r++)
						bitset[r][c] = true;

					//cout<<"TTD/DTT: "<<key<<endl;
				}
			}
		}
	}


	// top right diagonal
	for(size_t c = 1; c < cols; c++)
	{
		size_t r1 = 0;
		size_t c1 = c;

		while(r1 < rows && c1 < cols)
		{
			size_t r2 = r1 + 1;
			size_t c2 = c1 + 1;

			string key = "";
			key += grid[r1][c1];

			while(r2 < rows && c2 < cols)
			{
				key += grid[r2][c2];

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(size_t r = r1, c = c1; r <= r2 && c <= c2; r++, c++)
						bitset[r][c] = true;

					//cout<<"MDU/MDD: "<<key<<endl;
				}


				r2++;
				c2++;
			}

			r1++;
			c1++;
		}
	}

	// bottom left diagonal
	for(size_t r = 0; r < rows; r++)
	{
		size_t r1 = r;
		size_t c1 = 0;

		while(r1 < rows && c1 < cols)
		{
			size_t r2 = r1 + 1;
			size_t c2 = c1 + 1;

			string key = "";
			key += grid[r1][c1];

			while(r2 < rows && c2 < cols)
			{
				key += grid[r2][c2];

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(size_t r = r1, c = c1; r <= r2 && c <= c2; r++, c++)
						bitset[r][c] = true;

					//cout<<"MDU/MDD: "<<key<<endl;
				}


				r2++;
				c2++;
			}

			r1++;
			c1++;
		}
	}


	// top right to bottom left diagonal
	for(size_t c = 0; c < cols; c++)
	{
		int r1 = 0;
		int c1 = c;

		while(r1 < (int)rows && c1 >= 0)
		{
			int r2 = r1 + 1;
			int c2 = c1 - 1;

			string key = "";
			key += grid[r1][c1];

			while(r2 < (int)rows && c2 >= 0)
			{
				key += grid[r2][c2];

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(int r = r1, c = c1; r <= r2 && c >= c2; r++, c--)
						bitset[r][c] = true;

					//cout<<"RDU/RDD: "<<key<<endl;
				}

				r2++;
				c2--;
			}

			r1++;
			c1--;
		}
	}


	// top right to bottom left diagonal - right half
	for(size_t r = 1; r < rows; r++)
	{
		int r1 = r;
		int c1 = cols - 1;

		while(r1 < (int)rows && c1 >= 0)
		{
			int r2 = r1 + 1;
			int c2 = c1 - 1;

			string key = "";
			key += grid[r1][c1];

			while(r2 < (int)rows && c2 >= 0)
			{
				key += grid[r2][c2];

				string keyrev = key;
				reverse(keyrev.begin(), keyrev.end());

				vector<string>& wordsinmap = wmap[key.size()];

				if(find(wordsinmap.begin(), wordsinmap.end(), key) != wordsinmap.end() || 
					find(wordsinmap.begin(), wordsinmap.end(), keyrev) != wordsinmap.end())
				{
					for(int r = r1, c = c1; r <= r2 && c >= c2; r++, c--)
						bitset[r][c] = true;

					//cout<<"RDU/RDD: "<<key<<endl;
				}

				r2++;
				c2--;
			}

			r1++;
			c1--;
		}
	}

	return bitset;
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cerr<<"usage: "<<argv[0]<<" input_file"<<endl;
        return 1;
    }
    
	ifstream infile(argv[1]);
	string str;

    // input grid
	vector<string> grid;

    // map of words, where key is length of word, and 
    // value is a list (vector) of all words of that length
	map<size_t, vector<string> > wmap;

	// read grid
	while(1)
	{
		getline(infile, str);

		if(str.empty())
			break;

		grid.push_back(str);
	}

	// initialize wmap
	size_t maxlength = max(grid.size(), grid[0].size());
	for(size_t i=0; i<= maxlength; i++)
	{
		vector<string> vs;
		wmap[i] = vs;
	}	

	// read words
	while(!infile.eof())
	{
		getline(infile, str);

		if(wmap.find(str.size()) == wmap.end())
		{
			vector<string> list;
			wmap[str.size()] = list;
		}
		wmap[str.size()].push_back(str);
	}

	vector<vector<bool> > bitset = solve(grid, wmap);

	for(size_t r = 0; r < bitset.size(); r++)
		for(size_t c = 0; c < bitset[0].size(); c++)
			if(bitset[r][c] == false)
				cout<<grid[r][c];

	cout<<endl;
}