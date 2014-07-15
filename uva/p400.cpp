#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> fnames;
	string tmp;
	int nfiles, maxlen;	
	while (cin >> nfiles) {
		fnames.clear();
		maxlen = 0;
		for (int i = 0; i < nfiles; i++) {
			cin >> tmp;
			maxlen = max((int)tmp.size(), maxlen);
			fnames.push_back(tmp);
		}
		int width = min(60, maxlen + 2);
		int ncols = 60 / width;
		int nrows = nfiles / ncols;
		if (nrows * ncols < nfiles) {
			nrows++;
		}
		sort(fnames.begin(), fnames.end());
		cout << "------------------------------------------------------------\n";
		for (int i = 0; i < nrows; i++) {
			for(int j = 0; j < ncols; j++) {
				int findex = i + nrows * j;
				if (findex < nfiles) {
					cout << left << setw(width) << fnames[findex];
				}
			}
			cout << endl;
		}

	}


	return 0;
}