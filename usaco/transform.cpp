/*
ID: rajorsh2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
#define LEN 1000000

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

bool isequal(vector<string>& m1, vector<string>& m2)
{
	size_t N = m1.size();
	for(size_t i=0; i<N; i++)
		if(m1[i] != m2[i])
			return false;

	return true;
}


void rotate90(vector<string>& m, vector<string>& res)
{
	size_t N = m.size();
	for(size_t i=0; i<N; i++)
		for(size_t j=0; j<N; j++)
			res[j][N-i-1] = m[i][j];
}

void rotate180(vector<string>& m, vector<string>& res)
{
	vector<string> res2 = res;
	rotate90(m, res);
	rotate90(res, res2);
	res = res2;
}

void rotate270(vector<string>& m, vector<string>& res)
{
	vector<string> res2 = res;
	vector<string> res3 = res;
	rotate90(m, res);
	rotate90(res, res2);
	rotate90(res2, res3);
	res = res3;
}

void reflect(vector<string>& m, vector<string>& res)
{
	size_t N = m.size();
	for(size_t i=0; i<N; i++)
		for(size_t j=0; j<N; j++)
			res[i][N-j-1] = m[i][j];
}

void combine_rotate90(vector<string>& m, vector<string>& res)
{
	vector<string> res2 = res;
	reflect(m, res);
	rotate90(res, res2);
	res = res2;
}

void combine_rotate180(vector<string>& m, vector<string>& res)
{
	vector<string> res2 = res;
	reflect(m, res);
	rotate180(res, res2);
	res = res2;
}

void combine_rotate270(vector<string>& m, vector<string>& res)
{
	vector<string> res2 = res;
	reflect(m, res);
	rotate270(res, res2);
	res = res2;
}



int main() 
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	const int N = string_to_int(readline(fin));

	string buf(N, ' ');
	vector<string> m1(N, buf);
	vector<string> m2(N, buf);

	for(int i=0; i<N; i++)
		m1[i] = readline(fin);

	for(int i=0; i<N; i++)
		m2[i] = readline(fin);

	vector<string> res = m1;

	rotate90(m1, res);
	if(isequal(m2,res))
	{
		fout<<1<<endl;
		return 0;
	}

	rotate180(m1, res);
	if(isequal(m2,res))
	{
		fout<<2<<endl;
		return 0;
	}

	rotate270(m1, res);
	if(isequal(m2,res))
	{
		fout<<3<<endl;
		return 0;
	}

	reflect(m1, res);
	if(isequal(m2,res))
	{
		fout<<4<<endl;
		return 0;
	}

	combine_rotate90(m1, res);
	if(isequal(m2,res))
	{
		fout<<5<<endl;
		return 0;
	}

	combine_rotate180(m1, res);
	if(isequal(m2,res))
	{
		fout<<5<<endl;
		return 0;
	}

	combine_rotate270(m1, res);
	if(isequal(m2,res))
	{
		fout<<5<<endl;
		return 0;
	}

	if(isequal(m1, m2))
	{
		fout<<6<<endl;
		return 0;
	}
    
	fout<<7<<endl;
	return 0;
}