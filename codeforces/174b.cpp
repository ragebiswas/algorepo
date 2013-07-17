#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int a = 0, i = 0, f = 0;
    for(int p=0; p<s.size(); p++)
    {
        switch(s[p])
        {
        case 'A': a++; break;
        case 'F': f++; break;
        case 'I': i++; break;
        }
    }

    int ans = 0;
    for(int p=0; p<s.size(); p++)
    {
        if(s[p] == 'I' && i == 1)
            ans++;
        else if(s[p] != 'F' && i == 0)
            ans++;
    }

    cout<<ans<<endl;
    return 0;	
}