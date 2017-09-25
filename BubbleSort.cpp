/* Implement Bubble Sort using C++ */

#include <iostream>
using namespace std;
 
// Sorts an array arr[] of arbitrary size n using Bubble Sort.

void BubbleSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			// Comparing consecutive data and switching values if value at j > j+1.
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
		// Value at n-i-1 will be maximum of all the values below this index.
	}	
}	
 
int main()
{
	int n, i, k;
	cout << "\nEnter the number of data element to be sorted: ";
	cin >> n;
 
	int arr[n];
	
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	BubbleSort(arr, n);
	
    /* Display sorted array: */
	cout << "\nSorted Array:  ";
	for (i = 0; i < n; i++)
        cout<<"  "<<arr[i];
 
    cin >> k;
	return 0;
}
