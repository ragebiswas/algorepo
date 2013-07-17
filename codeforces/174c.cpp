#include <cstdio>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

inline void getavg(vector<int>& s)
{
    int sum = accumulate(s.begin(), s.end(), 0);
    double avg = sum*1.0/(s.size()*1.0);
    printf("%.6f\n", avg);
}

int main()
{
    vector<int> s(1, 0);
    int n = 1;
    int sum = 0;

    int nops;
    scanf("%d", &nops);

    while(nops--)
    {
        int opcode;
        scanf("%d", &opcode);
        int a,b,c;

        switch(opcode)
        {
        case 1:
            scanf("%d%d",&a, &b);
            for(int i=0; i<a; i++)
                s[i] += b;
            getavg(s);
            break;
        case 2:
            scanf("%d", &a);
            s.push_back(a);
            getavg(s);
            break;
        case 3:
            s.pop_back();
            getavg(s);
            break;
        }
    }

    return 0;	
}