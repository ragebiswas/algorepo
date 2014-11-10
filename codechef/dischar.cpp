#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int ncases;
    string str;
    cin >> ncases;
    while (ncases--) {
        cin >> str;
        vector<int> charpos('z'+1, -1);
        int curlen = 0, maxlen = 0;

        for (int i = 0; i < str.size(); ++i) {
            char ch = str[i];
            if (charpos[ch] != -1) {
                maxlen = max(curlen, maxlen);
                charpos[ch] = i;
            }
            else {
                charpos[ch] = i;
                curlen++;
            }
        }
        maxlen = max(curlen, maxlen);
        cout << maxlen << endl;
    }
    return 0;
}
