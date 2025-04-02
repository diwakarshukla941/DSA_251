#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int k) {
    k = k % size; // Handle cases where k > size
    reverse(arr, arr + size);
    reverse(arr, arr + k);
    reverse(arr + k, arr + size);
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