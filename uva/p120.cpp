#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void print(vector<int>& v)
{
	for(int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
}

int main()
{
	string line;
	int tmp;
	while (getline(cin, line)) {
		istringstream iss(line);
		vector<int> st;
		while (iss >> tmp) {
			st.push_back(tmp);
		}
		print(st);
		vector<int> stsorted = st;
		vector<int> flips;
		int i = 0;
		sort(stsorted.begin(), stsorted.end());
		while (stsorted != st) {
            // Step 1 : swap max element to the top
            vector<int>::iterator it = max_element(st.begin(), st.end() - i);
            if (it != st.begin()) {
                flips.push_back(st.end() - it);
                reverse(st.begin(), it + 1);
            }
            if (stsorted == st) {
                break;
            }
            // Step 2 get max element to correct position
            reverse(st.begin(), st.end() - i);
            flips.push_back(i + 1);
            i++;
		}
		flips.push_back(0);
		print(flips);
	}
	return 0;
}