#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string arr[4];

inline bool incomplete()
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(arr[i][j] == '.')
                return true;
     
    return false;
}

inline bool check(char p)
{
    bool pwon = true;
    
    // horizontals
    for(int i=0; i<4; i++)
    {
        pwon = true;
        for(int j=0; j<4; j++)
            if(arr[i][j] != p && arr[i][j] != 'T')
                pwon = false;
        
        if(pwon)
        {
            cout<<p<<" won\n"; 
            return true;
        }
    }
    
    // verticals
    for(int i=0; i<4; i++)
    {
        pwon = true;
        for(int j=0; j<4; j++)
            if(arr[j][i] != p && arr[j][i] != 'T')
                pwon = false;
        
        if(pwon)
        {
            cout<<p<<" won\n"; 
            return true;
        }        
    }
    
    // diagonal 1
    pwon = true;
    for(int i=0; i<4; i++)
        if(arr[i][i] != p && arr[i][i] != 'T')
            pwon = false;
            
    if(pwon)
    {
        cout<<p<<" won\n"; 
        return true;
    }              
    
    // diagonal 2
    pwon = true;
    for(int i=0; i<4; i++)
        if(arr[i][4-i-1] != p && arr[i][4-i-1] != 'T')
            pwon = false;
            
    if(pwon)
    {
        cout<<p<<" won\n"; 
        return true;
    }                

    return false;
}


int main()
{
    int nc;
    cin>>nc;

    for(int c=1; c<=nc; c++)
    {
        for(int i=0; i<4; i++)
            cin>>arr[i];

        cout<<"Case #"<<c<<": ";    
        if(!check('X') && !check('O'))
        {
            if(incomplete())
                cout << "Game has not completed\n";
            else
                cout<<"Draw\n";
        }
    }
    
    return 0;
}
    