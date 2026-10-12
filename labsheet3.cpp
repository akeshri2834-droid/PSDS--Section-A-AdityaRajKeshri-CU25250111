#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // middle index

        if (arr[mid] == key)
            return mid;                     // found
        else if (arr[mid] < key)
            low = mid + 1;                  // search the right half
        else
            high = mid - 1;                 // search the left half
    }
    return -1;                              // not found
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result == -1)
        cout << key << " not found\n";
    else
        cout << key << " found at index " << result << "\n";

    return 0;
}