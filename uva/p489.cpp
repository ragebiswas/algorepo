// Hangman Judge
// Easy coding
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{	
	int round, wa;
	string ans, guess, corr;
	while (1) {
		cin >> round;
		if (round == -1) {
			break;
		}
		else {
			cout << "Round " << round << endl;
		}
		cin >> ans >> guess;		
		
		string corr(ans.size(), ' ');
		wa = 0;
		
		for(int i = 0; i < guess.size(); i++) {
			if(ans.find(guess[i]) != string::npos) {
				for(int j = 0; j < ans.size(); j++) {
					if(ans[j] == guess[i]) {
						corr[j] = ans[j];
					}
				}
				if (corr == ans) {
					break;
				}
			}
			else {
				wa++;
				if (wa >= 7) {
					break;
				}
			}
		}
		if (corr == ans && wa < 7) {
			cout << "You win." << endl;
		}
		else if(corr != ans && wa < 7) {
			cout << "You chickened out." << endl;
		}
		else {
			cout << "You lose." << endl;
		}
	}
	return 0;
}