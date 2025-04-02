/*
Note:
This program rotates an array by k positions.
It uses reversal algorithm:
1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining elements.
This ensures the array is rotated efficiently in O(n) time with O(1) space.
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(int arr[], int size, int k) {
    k = k % size; // Handle cases where k > size
    reverseArray(arr, 0, size - 1);
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateArray(arr, size, k);
    cout << "Rotated Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
