/**
 * Problem: http://www.spoj.com/problems/HANGOVER/
 * Category: Simple coding
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string line;
    double tot;
    
    while (1) {
        cin >> line;
        
        if (line == "0.00")
            break;
            
        istringstream iss(line);
        iss >> tot;
        
        double len = 0;
        int last = 1, num = 0;
        
        while (1) {
            len += (1.0 / ++last);
            num++;
            if (len > tot) {
                cout << num << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}