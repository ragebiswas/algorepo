/*
ID: rajorsh2
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
	ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    
    int n, num_1, num_2, swaps = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    num_1 = count(arr.begin(), arr.end(), 1);
    num_2 = count(arr.begin(), arr.end(), 2);

    // Step 1: Sort 1s
    for (int i = num_1; i < n; i++) {
        if (arr[i] == 1) {
            int swap_from = -1;
            for (int t = 0; t < num_1; t++) {
                if (arr[t] == 2) {
                    swap_from = t;
                    break;
                }
                else if (arr[t] == 3) {
                    swap_from = t;
                }
            }
            if (swap_from != -1) {
                swaps++;
                swap(arr[i], arr[swap_from]);
            }
        }
    }

    // Step 2: Sort 2s
    for (int i = num_1 + num_2; i < n; i++) {
        if (arr[i] == 2) {
            for (int t = num_1; t < num_1 + num_2; t++) {
                if (arr[t] == 3) {
                    swaps++;
                    swap(arr[t], arr[i]);
                    break;
                }
            }
        }
    }

    cout << swaps << endl;
	return 0;
}