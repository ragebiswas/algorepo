#include <iostream>
#include <vector>

using namespace std;

void spiral_print(vector<string> m)
{
	int rows = m.size();
	int cols = m[0].size();

	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };

	int d = 0;

	int numr = rows-1;
	int numc = cols;

	bool horiz = true;
	bool complete = false;
	
	int cr = 0;
	int cc = -1;

	while(1)
	{
		for(int i=0; i<3; i++)
		{
			if(horiz)
			{
				for(int s=0; s<numc; s++)
				{
					cr = cr+dr[d];
					cc = cc+dc[d];
					cout<<m[cr][cc];
				}
				numc--;
			}
			else
			{
				for(int s=0; s<numr; s++)
				{
					cr = cr+dr[d];
					cc = cc+dc[d];
					cout<<m[cr][cc];
				}
				numr--;
			}

			cout<<endl;
			horiz = !horiz;
			d = (d+1)%4;

			if((horiz && numc <= 0) || (!horiz && numr <= 0))
			{
				complete = true;
				break;
			}
		}

		if(complete)
			break;

	}

}

void spiral_run()
{
	vector<string> matrix;
	matrix.push_back("abcde12");
	matrix.push_back("fghij34");
	matrix.push_back("klmno56");
	matrix.push_back("pqrst78");

	spiral_print(matrix);
}