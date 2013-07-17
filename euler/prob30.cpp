#include <iostream>
using namespace std;

int pow5(int n)
{
    return n*n*n*n*n;
}

int getsum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += pow5(n%10);
        n/=10;
    }
    return sum;
}

int main()
{
    int i = 10;
    long long s = 0;
    while(i < 999999)
    {
        if(i == getsum(i))
        {
            cout<<"Found: "<<i<<endl;
            s += i;
        }
        i++;
    }
    
    cout<<"Total sum: "<<s<<endl;
    return 0;
}