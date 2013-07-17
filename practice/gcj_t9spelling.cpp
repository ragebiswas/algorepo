#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("C-small.in");
    char str[2000];
    int nc = 0;
    
    ifs.getline(str, 2000);
    string s = str;
    istringstream iss(s);
    iss>>nc;
    int c = 1;
    
    map<char, pair<string, int> >  code;
    int digit = 2;
    int repcount = 1;
    
    for(int i = 'a'; i <= 'z'; i++)
    {
            if(repcount > 3 && (i != 's' && i != 'z'))
            {
                repcount = 1;
               digit++;
            } 
              
            string curcode = "";
            for(int j = 0; j < repcount; ++j)
            {
                curcode += (digit + '0');
            }
            code[i] = make_pair(curcode, digit);
            repcount++;
    }
        
    while(ifs.getline(str, 2000))
    {
        string s = str;
        cout<<"Case #"<<c++<<": ";
        
        int pdig = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            int dig;
            if(ch >= 'a' && ch <= 'z')
            dig = code[ch].second;
            else dig = -1;
            
            if(dig == pdig)
                cout<<" ";
            
            if(ch==' ')
            {
                cout<<"0";
                pdig = -1;
            }
            else
            {
                cout<<code[ch].first;     
                pdig = dig;
            }
                
        }
        
        cout<<endl;

    }
    
    
    return 0;
}
