// C++ program to check if a given array is sorted
// or not.
/*Time complexity: O(n) where n is the size of array
Auxiliary Space: O(1)*/
#include<bits/stdc++.h>
using namespace std;

// Function that returns true if array is Inorder
// traversal of any Binary Search Tree or not.
bool isInorder(int arr[], int n)
{
	// Array has one or no element
	if (n == 0 || n == 1)
		return true;

	for (int i = 1; i < n; i++)

		// Unsorted pair found
		if (arr[i-1] > arr[i])
			return false;

	// No unsorted pair found
	return true;
}

// Driver code
int main()
{
	int arr[] = { 19, 23, 25, 30, 45 };
	int n = sizeof(arr)/sizeof(arr[0]);

	if (isInorder(arr, n))
		cout << "Yes";
	else
		cout << "No";

return 0;
}
