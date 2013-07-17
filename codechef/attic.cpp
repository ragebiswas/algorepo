#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string p;

int calc() {
    int maxholes = 0;
    bool inhole = false;
    int curholes = 1;
    p += "#";
    int days = 0;

    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '.') {
            if(inhole) {
                curholes++;
                continue;
            }
            else {
                inhole = true;
            }
        }
        else {
            if(inhole) {
                inhole = false;
                if(curholes > maxholes) {
                    days++;
                    maxholes = curholes;
                }
                curholes = 1;
            }
        }
    }


    return days;
}


int main() 
{
    int nc;
    cin>>nc;

    while(nc--) {
        cin>>p;
        cout<<calc()<<endl;
    }

    return 0;
}