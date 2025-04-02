#include <iostream>
#include <limits.h>
using namespace std;

int findSecondLargest(int arr[], int size) {
    if (size < 2) {
        cout << "Array should have at least two elements" << endl;
        return -1;
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
    int arr[] = {10, 20, 4, 45, 99, 99, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findSecondLargest(arr, size);
    if (result != -1)
        cout << "The second largest element is: " << result << endl;
    else
        cout << "No second largest element found" << endl;
    return 0;
}
