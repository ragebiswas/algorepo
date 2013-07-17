#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class DisjointSet
{
private:
	vector<int> s;
public:
	DisjointSet(int num): s(num)
	{
		for(int i=0; i<num; ++i)
			s[i] = -1;
	}
	void setUnion(int r1, int r2)
	{
        r1 = setFind(r1);
        r2 = setFind(r2);
        
		if(s[r2] < s[r1])
			s[r1] = r2;
		else
		{
			if(s[r1] == s[r2])
				s[r1]--;
			s[r2] = r1;
		}
	}
	int setFind(int r)
	{
		if(s[r] < 0)
			return r;
		else
			return s[r] = setFind(s[r]);
	} 
};

int main(int argc, char **argv)
{
	int num, p1, p2, y = 0, n = 0;
	char t;
	ifstream infile(argv[1]);
	infile>>num;
	DisjointSet dset(num+1);
	while(infile>>t>>p1>>p2)
	{
		switch(t)
		{
		case 'c':	if(dset.setFind(p1) != dset.setFind(p2)) 
						dset.setUnion(p1, p2); 
					break;

		case 'q':	(dset.setFind(p1) == dset.setFind(p2)) ? y++ : n++;
					break;
		}
	}
	cout<<y<<","<<n<<endl;
	infile.close();
}


