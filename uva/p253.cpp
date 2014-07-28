#include <iostream>
#include <vector>
using namespace std;

const string master_rotations[] = {
    "123456",
    "263415",
    "365214",
    "462513",
    "564312",
    "624351"        
};
vector<string> rotations;

void genallrotations()
{
    for (int i = 0; i < 6; i++) {
        string mr = master_rotations[i];
        rotations.push_back(mr);
        for (int j = 0; j < 3; j++) {
            string nr = mr;
            nr[1] = mr[2];
            nr[2] = mr[4];
            nr[3] = mr[1];
            nr[4] = mr[3];
            rotations.push_back(nr);
            mr = nr;
        }
    }
}

void solve(string s1, string s2)
{
    bool same = false;
    for (int i = 0; i < rotations.size(); i++) {
        string rot = s1;
        for (int j = 0; j < 6; j++) {
            rot[j] = s1[rotations[i][j] - '1'];
        }
        if (rot == s2) {
            same = true;
            break;
        }
    }

    if (same) {
        cout << "TRUE\n";
    }
    else {
        cout << "FALSE\n";
    }
}


int main()
{
    string str, s1, s2;
    genallrotations();

    while (getline(cin, str)) {
        s1 = str.substr(0, 6);
        s2 = str.substr(6, 12);
        solve(s1, s2);
    }
    return 0;
}