#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

vector<string> teams;
vector<int> points, wins, ties, losses, goalscored, goalagainst, games;
map<string, int> tmap;

void printstat(int rank, string team)
{
	int t = tmap[team];
	cout << rank << ") " << team << " ";
	cout << points[t] << "p, ";
	cout << games[t] << "g ";
 	cout << "(" << wins[t] << "-" << ties[t] << "-" << losses[t] << "), ";
 	cout << goalscored[t] - goalagainst[t] << "gd ";
 	cout << "(" << goalscored[t] << "-" << goalagainst[t] << ")";
	cout << endl;
}

bool comp(string team1, string team2) {
	int t1 = tmap[team1];
	int t2 = tmap[team2];

	// by points
	if (points[t1] > points[t2]) {
		return true;
	} 
	else if (points[t2] > points[t1]) {
		return false;
	}

	// by wins
	if (wins[t1] > wins[t2]) {
		return true;
	}
	else if (wins[t2] > wins[t1]) {
		return false;
	}

	// by goal difference
	int gd1 = goalscored[t1] - goalagainst[t1];
	int gd2 = goalscored[t2] - goalagainst[t2];
	if (gd1 > gd2) {
		return true;
	}
	else if (gd2 > gd1) {
		return false;
	}

	// by goals scored
	if (goalscored[t1] > goalscored[t2]) {
		return true;
	}
	else if (goalscored[t2] > goalscored[t1]) {
		return false;
	}

	// less games played
	if (games[t1] < games[t2]) {
		return true;
	}
	else if (games[t2] < games[t1]) {
		return false;
	}

	// case insensitive compare, finally
	transform(team1.begin(), team1.end(), team1.begin(), ::tolower);
	transform(team2.begin(), team2.end(), team2.begin(), ::tolower);
	return team1 < team2;
}

void process()
{
	sort(teams.begin(), teams.end(), comp);
	for (int i = 0; i < teams.size(); i++) {
		printstat(i + 1, teams[i]);
	}
}




int main()
{
	int ntours, nteams, ngames;
	string tname, tmp;
	
	char at;
	cin >> ntours;
	cin.ignore(512, '\n');

	for(int nt = 0; nt < ntours; nt++) {		
		getline(cin, tname);	

		cin >> nteams;
		teams.clear();
		tmap.clear();
		points.clear();
		wins.clear();
		ties.clear();
		losses.clear();
		goalscored.clear();
		goalagainst.clear();
		games.clear();

		points.resize(nteams, 0);
		wins.resize(nteams, 0);
		ties.resize(nteams, 0);
		losses.resize(nteams, 0);
		goalscored.resize(nteams, 0);
		goalagainst.resize(nteams, 0);
		games.resize(nteams, 0);

		cin.ignore(512, '\n');
		for (int i = 0; i < nteams; i++) {
			getline(cin, tmp);
			teams.push_back(tmp);
			tmap[tmp] = i;
		}

		cin >> ngames;
		cin.ignore(512, '\n');
		while (ngames--) {
			// input parsing
			getline(cin, tmp);
			size_t h1 = tmp.find('#');
			size_t h2 = tmp.find('#', h1 + 1);
			string team1 = tmp.substr(0, h1);
			string team2 = tmp.substr(h2 + 1);
			string scorestr = tmp.substr(h1 + 1, h2 - h1 - 1);
			int score1, score2;			
			istringstream iss(scorestr);
			iss >> score1 >> at >> score2;
			int t1 = tmap[team1];
			int t2 = tmap[team2];
			
			// book keeping starts
			goalscored[t1] += score1;
			goalagainst[t1] += score2;
			goalscored[t2] += score2;
			goalagainst[t2] += score1;

			games[t1]++;
			games[t2]++;


			if (score1 > score2) {
				points[t1] += 3;
				wins[t1]++;
				losses[t2]++;
			}
			else if (score1 < score2) {
				points[t2] += 3;
				wins[t2]++;
				losses[t1]++;
			}
			else {
				points[t1]++;
				points[t2]++;
				ties[t1]++;
				ties[t2]++;
			}
		}
		cout << tname << endl;
		process();

		if (nt != ntours - 1) {
			cout << endl;
		}

	}
	return 0;
}