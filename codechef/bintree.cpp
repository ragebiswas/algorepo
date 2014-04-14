// Codechef April 2014 Long
// Easy binary tree logic
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int a, b, d = 0;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        map<int, int> apath, bpath;
        while (a) {
            apath[a] = d++;
            a /= 2;
        }
        d = 0;
        while (b) {
            bpath[b] = d++;
            b /= 2;
        }

        int ans = 0;
        for (map<int, int>::reverse_iterator i = bpath.rbegin(); i != bpath.rend(); i++) {
            ans = i->second;
            if (apath.find(i->first) != apath.end()) {
                ans += apath[i->first];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
    
}