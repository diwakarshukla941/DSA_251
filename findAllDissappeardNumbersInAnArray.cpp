#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find all disappeared numbers in an array
vector<int> findDisappearedNumbers(vector<int>& nums) {
    // Step 1: Mark indices as visited using negative values
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1; // Get the correct index (1-based to 0-based)
        
        // If the value at that index is positive, mark it negative
        if (nums[index] > 0) {
            nums[index] = -nums[index]; // Mark as visited
        }
    }

    // Step 2: Collect indices that are still positive (unvisited)
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1); // i+1 is the missing number
        }
    }

    return result; // Return the result vector
}

int main() {
    // Input array
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    // Call the function to find missing numbers
    vector<int> missing = findDisappearedNumbers(nums);

    // Output the result
    cout << "Missing numbers are: ";
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
🔍 EXPLANATION:

Given: An array "nums" of size n containing numbers from 1 to n (some may appear twice, some may be missing).

👉 Goal: Find all numbers in the range [1, n] that are missing from the array.

### 🔧 Logic Used:
We mark visited indices using negative signs:
- For every number `x` in the array, we calculate `index = abs(x) - 1`.
- We mark `nums[index]` as negative to indicate that the number `x` has been seen.

After marking:
- Any index `i` whose value is still positive means number `i+1` was **not** present in the original array.

### 🧪 Example:
Input:  [4, 3, 2, 7, 8, 2, 3, 1]

Step 1 (marking):
- After marking, array becomes: [-4, -3, -2, -7, 8, 2, -3, -1]

Step 2 (collecting):
- Indices 4 and 5 have positive values (8 and 2), so 5 and 6 are missing.

✅ Final Output:
Missing numbers are: 5 6
*/
