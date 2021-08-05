/*
Niave approach:

Linear search

TC = O(N)
SC = O(1)

Efficient approach: BINARY SEARCH (iterative)

array sorted hai to BS click hona chaiye
ab array rotated hai isiliye do sorted subarrays banengi and BS dono me alag se lagaao

ex: { 5, 6, 7, 8, 9, 10, 1, 2, 3 }

BS 1>> 5, 6, 7, 8, 9, 10 
BS 2>> 1, 2, 3  


TC = O(logN) + O(logN) => O(logN)  
SC = O(1)   
*/

#include <bits/stdc++.h>
using namespace std;

//binary search iterative
int BS(int arr[],int n,int low,int high,int key)
{
	int flag=0;
	
	int mid=low+(high-low)/2;
	while(high>=low)
	{
		if(arr[mid]==key)
		{
			//cout<<"\nKey is found at index no "<<mid;
			return mid;
			flag=1;
			break;
		}
		else if(arr[mid]>key)  //go left
		{
			high=mid-1;
		}
		else if(arr[mid]<key)  //go right
		{
			low=mid+1;
		}
	}
	if(flag==0)
	{
			return -1;
	}
}

int findPivot(int arr[], int low, int high)
{
    // base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}

int Search(int arr[],int n,int key)
{
	//use binary search itself to find pivot point ((COPIED FROM GFG))
	 int pivot = findPivot(arr, 0, n - 1);
	 
	 //Do BS from arr[0--pivot] and arr[pivot+1--n-1]
	 int a=BS(arr,n,0,pivot,key);
	 return a;
	 if(a==-1)
	 {
	 	int b=BS(arr,n,pivot+1,n-1,key);
	 	return b;
	 }
	 
}

/* Driver program to check above functions */
int main()
{
    // Let us search 3 in below array
    int arr[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
 
    // Function calling
    cout << "Index of the element is : "<< Search(arr, n, key);
 
    return 0;
}
