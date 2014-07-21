#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char getdigit(char c)
{
    c = toupper(c);
    switch(c) {
        case 'A' : case 'B': case 'C': return '2';
        case 'D' : case 'E': case 'F': return '3';
        case 'G' : case 'H': case 'I': return '4';
        case 'J' : case 'K': case 'L': return '5';
        case 'M' : case 'N': case 'O': return '6';
        case 'P' : case 'R': case 'S': return '7';
        case 'T' : case 'U': case 'V': return '8';
        case 'W' : case 'X': case 'Y': return '9';
    }
    return c;
}

string format(string num)
{
    string n = "";
    for (int i = 0; i < num.size(); i++) {
        if (n.size() == 3) {
            n += "-";
        }
        if (isdigit(num[i])) {
            n += num[i];
        }
        else if (isalpha(num[i])) {
            n += getdigit(num[i]); 
        }
    }
    return n;
}

int main()
{
    int nc;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        int n;
        cin >> n;
        string num;
        vector<string> nums;
        map<string, int> m;
        for (int j = 0; j < n; j++) {
            cin >> num;
            num = format(num);
            if (m.find(num) == m.end()) {
                m[num] = 0;
                nums.push_back(num);
            }
            m[num]++;
        }
        sort(nums.begin(), nums.end());
        bool nodups = true;
        for (int j = 0; j < nums.size(); j++) {
            if (m[nums[j]] > 1) {
                cout << nums[j] << " " << m[nums[j]] << endl;
                nodups = false;
            }
        }

        if (nodups) {
            cout << "No duplicates." << endl;
        }

        if (i != nc - 1) {
            cout << endl;
        }
    }
    return 0;
}