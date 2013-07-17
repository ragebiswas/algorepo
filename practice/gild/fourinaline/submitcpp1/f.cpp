#include <string>
#include <fstream>
#include <iostream>
using namespace std;

static string p1 = "1,1,1,1", p2 = "2,2,2,2";
static string ringbuf[4];

int main(int argc, char** argv)
{
	ifstream fin(argv[1]);	
	int i = 0, k = 0, sz = 0, ended = 1;

	while(getline(fin, ringbuf[i]))
	{
		cout<<ringbuf[i]<<endl;
  }
	return 0;
}