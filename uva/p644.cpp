// Immediate decodability (Level 1: String)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool prefix(string a, string b) 
{
	if (a.size() < b.size()) {
		swap(a, b);
	}
	if (a.find(b) == 0) {
		return true;
	}
	return false;
}

int main()
{
	string tmp;
	vector<string> codes;
	int set = 1;
	while (cin >> tmp) {
		if (tmp == "9") {
			bool ret = true;
			for (int i = 0; i < codes.size(); i++) {
				for (int j = 0; j < codes.size(); j++) {
					if (i != j && prefix(codes[i], codes[j])) {
						ret = false;
						break;
					}
				}
			}
			if (ret == true) {
				cout << "Set " << set << " is immediately decodable" << endl;
			}
			else {
				cout << "Set " << set << " is not immediately decodable" << endl;	
			}
			codes.clear();
			ret = true;
			set++;
		}
		else {
			codes.push_back(tmp);
		}
	}
	return 0;
}