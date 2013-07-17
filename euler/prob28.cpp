#include <iostream>
#include <cstdlib>

using namespace std;

const int SZ = 1001;

int arr[SZ][SZ];

void print()
{
    for(int i=0; i<SZ; i++)
    {
        for(int j=0; j<SZ; j++)
        {
            cout.width(12);
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    int x, y, v;
    int x0, y0;
    x = y = x0 = y0 = SZ/2;
    v = 1;
    
    int curidx = 1; // index of dx
    int curidy = 1; // index of dy
    
    int newx, newy;
    int diff = 1;
    
    arr[y][x] = v++;
    arr[y][x+1] = v++;
    x++;
    
    while(1)
    {
        newx = x + dx[curidx];
        newy = y + dy[curidy];
        
        if((abs(newx-x0) > diff || abs(newy-y0) > diff))
        {
            if(dx[curidx] == 1)
            {
                newx = x + dx[curidx];
                newy = y + dy[curidy];
                
                curidx = (curidx+1)%4;
                curidy = (curidy+1)%4;
                
                diff++;
            }
            else
            {
                curidx = (curidx+1)%4;
                curidy = (curidy+1)%4;
                
                newx = x + dx[curidx];
                newy = y + dy[curidy];
            }
        }
        
        x = newx;
        y = newy;
        
        if(x >= SZ || y >= SZ)
            break;
        
        arr[y][x] = v++;    
    }

    //print();
    
    long long sum = 0;
    for(int i=0; i<SZ; i++)
    {
        sum += arr[i][i];
        sum += arr[i][SZ-i-1];
    }
    sum--;
    
    cout<<"Diagonal sum: "<<sum<<endl;
    
    return 0;
}