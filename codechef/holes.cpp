// holes
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n; 
    cin>>n;
    
    string hole = "ABDOPQR";    
    
    while(n--) 
    {
        string str;
        cin>>str;
        int cnt = 0;
        for(int i=0; i<str.size(); i++)
        {
            if(hole.find(str[i]) != string::npos)
                cnt++; 
            if(str[i] == 'B')
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}