#include <vector>
#include <iostream>
#include <string>

using namespace std;

int m[100][100];

void reset()
{
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            m[i][j] = 0;
}

void fw(int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
}


int main() 
{
    int n;
    cin>>n;
    vector<pair<int, int> > data;

    while(n--) 
    {
        int t, a, b;
        cin>>t>>a>>b;
        if(t == 1) 
        {
            data.push_back(make_pair(a, b));
            reset();
            int g = data.size();
            for(int i=0; i<g; i++)
            {
                for(int j=0; j<g; j++) 
                {
                    if(i!=j)
                    {
                        int a = data[i].first;
                        int b = data[i].second;
                        int c = data[j].first;
                        int d = data[j].second;

                        if((c<a && a<d) || (c<b && b<d))
                            m[i][j] = 1;
                    }
                }
            }  
            fw(data.size());
        }
        else
        {
            a--;
            b--;
            if(m[a][b] == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }


    return 0;
}