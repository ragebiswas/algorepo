#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("B-small.in");
    char str[2000];
    int nc = 0;
    
    ifs.getline(str, 2000);
    string s = str;
    istringstream iss(s);
    iss>>nc;
    int c = 1;
        
    while(ifs.getline(str, 2000))
    {
        string s = str;
        istringstream iss2(s);
        string word;
        vector<string> words;
        
        while(iss2>>word)
        {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        cout<<"Case #"<<c++<<": ";
        int i;
        for(i=0; i < words.size()-1; i++)
        {
            string rw = words[i];
            cout<<rw<<" ";
        }
        cout<<words[i]<<endl;        
    }
    
    
    return 0;
}
