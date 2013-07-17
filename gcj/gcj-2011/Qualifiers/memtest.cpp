#include <iostream>
using namespace std;

int main()
{
    int **m;
    m = new int*[100];
    
    for(int i=0; i<100; i++)
        m[i] = new int[100000000];
    
    cout<<sizeof(m);
    return 0;
}