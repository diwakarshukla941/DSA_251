#include <iostream>
#include <vector>
using namespace std;

bool canBeNonDecreasing(vector<int>& arr) {
    int n = arr.size();
    int count = 0; // To count violations
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) { // Found a violation
            count++;
            if (count > 1) return false; // More than 1 modification needed
            
            // Try modifying arr[i] if possible
            if (i == 0 || arr[i - 1] <= arr[i + 1]) {
                arr[i] = arr[i + 1];
            } 
            // Otherwise, modify arr[i+1] only if arr[i] <= arr[i+2] (or i+2 is out of bounds)
            else if (i + 2 >= n || arr[i] <= arr[i + 2]) {
                arr[i + 1] = arr[i];
            } else {
                return false; // If neither modification works, return false
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> testCases = {{8, 4, 6}, {8, 4, 2}, {-2, 7, -1, 0, 1, 2}, {-10, 10, 0, 10, 3}, {3, 4, 2, 3}};
    
    for (auto& arr : testCases) {
        cout << (canBeNonDecreasing(arr) ? "true" : "false") << endl;
    }
    return 0;
}
