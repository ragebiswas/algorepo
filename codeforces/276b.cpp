#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool ispossiblepal(string& s) 
{
    vector<int> c(26, 0);

    for(int i = 0; i < s.size(); i++)
    {
        c[s[i]-'a']++;
    }

    bool onechar = false;
    for(int i = 0; i < 26; i++)
    {
        if (c[i] %2 == 1) 
        {
            if(onechar == false)
                onechar = true;
            else
                return false;
        }
    }

    return true;
}


int main() 
{
    string s;
    cin>>s;

    if(ispossiblepal(s))
        cout<<"First\n";
    else 
        cout<<"Second\n";

    return 0;
}