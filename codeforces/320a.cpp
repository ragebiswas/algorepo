#include <vector>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

bool ismagic(string s)
{
    if(s.size() == 0)
        return true;

    bool t1 = false;
    bool t2 = false;
    bool t3 = false;

    if(s.substr(0, 1) == "1")
        t1 = ismagic(s.substr(1));

    if(s.size() >= 2 && s.substr(0, 2) == "14")
        t2 = ismagic(s.substr(2));

    if(s.size() >= 3 && s.substr(0,3) == "144")
        t3 = ismagic(s.substr(3));

    return t1 || t2 || t3;
}



int main() 
{
    int n;
    cin>>n;
    stringstream ss;
    ss<<n;
    string s = ss.str();
    if(ismagic(s))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}