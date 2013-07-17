#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int sumofdivs(int x)
{
    vector<int> divs;
    map<int, bool> m;
    divs.push_back(1);
       
    for(int i = 2; i<=x/2; i++)
    {
        if(x % i == 0)
        {
            if(m.find(i) == m.end())
            {    
                divs.push_back(i);
                m[i] = true;
            }
                
            int t = x/i;
            
            if(m.find(t) == m.end())
            {
                divs.push_back(t);
                m[t] = true;
            }
        }
    }
    return accumulate(divs.begin(), divs.end(), 0);
}

int getamicable(int x)
{
    int divsum1 = sumofdivs(x);
    if((x != divsum1) && (x == sumofdivs(divsum1)))
    {
        cout<<divsum1<<" and "<<x<<" are amicable\n";
        return x+divsum1;
    }
    else
    {
        return 0;
    }
}

const int MAX=10000;

int main()
{
    int sum = 0;
    for(int i=2; i<=MAX; i++)
    {
        sum += getamicable(i);
    }
    cout<<sum/2<<endl;

}