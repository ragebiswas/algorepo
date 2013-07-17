#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> v1, vector<int> v2)
{
	size_t index1 = v1.size() - 1;
	size_t index2 = v2.size() - 1;

	while (index2 >= 0)
	{
		int max1 = v1[index1];
		int max2 = v2[index2];

		if (max2 >= max1)
		{
			index2--;
			continue;
		}
		else
		{
			v2[index2] = max1;

			// place max2 in proper place in v1
			int insertpos = index1;
			while(insertpos--)
			{

			}
		}
	}

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << endl;
	}
	cout << "---\n";
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << endl;
	}

}

void merge_run()
{
	int arr1[4] =
	{ 1, 3, 5, 7 };
	vector<int> v1(arr1, arr1 + 4);

	int arr2[3] =
	{ 2, 4, 6 };
	vector<int> v2(arr2, arr2 + 3);

	merge(v1, v2);

}
