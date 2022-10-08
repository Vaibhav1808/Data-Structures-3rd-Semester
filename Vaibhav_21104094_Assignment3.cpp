/*
                                            Assignment 3
NAME - VAIBHAV
SID - 21104094
BRANCH - EE
*/

//APPLY BINARY SEARCH WHEN THE SIZE OF AN ARRAY IS UNKNOWN?

#include <bits/stdc++.h>
using namespace std;

// CREATING THE FUNCTION SUCH THAT WE ARE NOT PASSING THE SIZE OF THE ARRAY TO THE FUNCTION.

// LINEAR SEARCH

// In Linear Search we are traversing the array, and not keeping any limitation on the the traversing index(i).
int linear_search(int arr[], int x)
{
    for (int i = 0;; i++) 
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}    

// BINARY SEARCH

//This function is a simple Binary Search function where left and right indexes are being provided.

int binary_search_code(int arr[],int l,int r,int x) 
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}

//Trying to reduce our to O(log(N)) time complexity, by increasing the range of our search exponentitaly by 2.

// Optimised Binary Search
int binary_search(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x) //if element to be found is still high the value at high index .
    {
        low = high; //updating the low value
        high = 2 * high; //double the range of search, when the condition is satisfies then we call BINARY SEARCH on that range(low to high).
    }

    return binary_search_code(arr,low,high,x);
}

// Driver Code
int main()
{
    int *arr = new int[10000];
    int n;
    cout << " The number of elements in an array : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "ENTER THE ELEMENT YOU WANT TO SEARCH FOR : ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from LINEAR SEARCH is : " << linear_search(arr, x) << endl;
    cout << "Index of " << x << " from BINARY SEARCH is : " << binary_search(arr, x) << endl;
    delete[] arr;
}