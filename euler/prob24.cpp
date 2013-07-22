#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    vector<int> v;
    for(int i=0; i<10; i++)
        v.push_back(i);

    int c = 1;
    do {
        if(c == 1000000) {
            for(int i=0; i<10; i++)
                cout<<v[i];
            cout<<endl;
            break;
        }
        c++;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
