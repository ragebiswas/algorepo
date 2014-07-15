#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>
#include <utility>
using namespace std;

string join(vector<string>& arr)
{
    string ret = "";
    if (arr.size() < 1) {
        return ret;
    }
    for (int i = 0; i < arr.size() - 1; i++) {
        ret += (arr[i] + " ");
    }
    ret += arr[arr.size() - 1];
    return ret;
}

bool comp(pair<string, string> k1, pair<string, string> k2)
{
    return k1.second < k2.second;
}

int main()
{
    vector<string> titles;
    map<string, bool> iwords;
    string tmp;
    bool done = false;
    while (getline(cin, tmp)) {
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if (tmp == "::") {
            done = true;
        }
        else {
            if (!done) {
                iwords[tmp] = true;
            }
            else {
                titles.push_back(tmp);
            }
        }
    }
    vector<pair<string, string> > kwic;
    for (int i = 0; i < titles.size(); i++) {
        istringstream iss(titles[i]);
        string token;
        vector<string> words;
        while (iss >> token) {
            words.push_back(token);
        }
        for (int i = 0; i < words.size(); i++) {
            vector<string> mtitlearr;
            if (iwords.find(words[i]) == iwords.end()) {
                string upper = "";
                for (int j = 0; j < words.size(); j++) {
                    if (j == i) {
                        upper = words[j];
                        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
                        mtitlearr.push_back(upper);
                    }
                    else {
                        mtitlearr.push_back(words[j]);
                    }
                }
                kwic.push_back(make_pair(join(mtitlearr), upper));
            }            
        }
    }
    stable_sort(kwic.begin(), kwic.end(), comp);
    for (int i = 0; i < kwic.size(); i++) {
        cout << kwic[i].first << endl;
    }
    return 0;
    
}