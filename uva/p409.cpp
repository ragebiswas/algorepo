// Excuses, Excuses! (Level 1)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
#define MLEN 10240

string tolowercase(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

int score(string excuse, map<string, bool> kwmap)
{
	for (int i = 0; i < excuse.size(); i++) {
		if (!isalpha(excuse[i])) {
			excuse[i] = ' ';
		}
	}

	istringstream iss(excuse);
	string tmp;
	int score = 0;
	while (iss >> tmp) {
		tmp = tolowercase(tmp);
		if (kwmap.find(tmp) != kwmap.end()) {
			score++;
		}
	}
	return score;
}

int main()
{
	int K, E, c = 1;	
	string tmp;
	while (cin >> K >> E) {
		string excuse;
		vector<string> answers;
		int maxscore = 1;
		map<string, bool> kwmap;
		for (int i = 0; i < K; i++) {
			cin >> tmp;
			tmp = tolowercase(tmp);
			kwmap[tmp] = true;
		}
		cin.ignore(MLEN, '\n');
		for (int i = 0; i < E; i++) {
			getline(cin, excuse);
			int curscore = score(excuse, kwmap);
			//cout << "Score for '" << excuse << "' is : " << curscore << endl;
			if (curscore >= maxscore) {
				if (curscore > maxscore) {
					answers.clear();
					maxscore = curscore;
				}
				answers.push_back(excuse);
			}
		}
		cout << "Excuse Set #" << c++ << endl; 
		for (int i = 0; i < answers.size(); i++) {
			cout << answers[i] << endl;
		}

		cout << endl;
	}
	return 0;
}