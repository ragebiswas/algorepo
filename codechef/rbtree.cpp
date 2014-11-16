#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool inverted = false;
enum Color { BLACK, RED };

int log2(int n) 
{
    int lv = 0;
    while (n >>= 1) {
        ++lv;
    }
    return lv;
}

int calc(map<int, int>& m, Color color) 
{
    int ret = 0, log2val;
    for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
        log2val = log2(it->first);
        if (inverted) {
            if (log2val % 2 == 1 && color == BLACK) {
                ret++;
            }
            if (log2val %2 == 0 && color == RED) {
                ret++;
            }
        }
        else {
            if (log2val % 2 == 1 && color == RED) {
                ret++;
            }
            if (log2val %2 == 0 && color == BLACK) {
                ret++;
            }
        }
    }
    return ret;
}

int find(int node1, int node2, Color color)
{
    int n1 = node1, n2 = node2; 
    map<int, int> path1, path2;
    int anc = -1;

    while (n1) {
        path1[n1] = 1;
        n1 /= 2;
    }
    while (n2) {
        if (path1.find(n2) != path1.end()) {
            anc = n2;
            break;
        }
        path2[n2] = 1;
        n2 /= 2;
    }
    anc /= 2;
    while(anc) {
        path1.erase(anc);
        anc /= 2;
    }

    int ans = calc(path1, color);
    ans += calc(path2, color);
    return ans;
}

int main()
{
    int nc;
    cin >> nc;
    while (nc--) {
        string cmd;
        int n1, n2;
        cin >> cmd;
        switch(cmd[1]) {
            case 'i':
                inverted = !inverted;
                break;
            case 'b':
                cin >> n1 >> n2;
                cout << find(n1, n2, BLACK) << "\n";
                break;
            case 'r':
                cin >> n1 >> n2;
                cout << find(n1, n2, RED) << "\n";
                break;
        }
    }
    return 0;
}
