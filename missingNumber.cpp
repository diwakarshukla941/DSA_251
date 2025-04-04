#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Naive Approach: Sort the array and check index mismatch
class NaiveSolution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array

        // Check for the first index where nums[i] != i
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) {
                return i; // This is the missing number
            }
        }

        // If all numbers from 0 to n-1 are present, then n is the missing number
        return n;
    }
};

// Optimized Approach: Using sum formula
class FormulaSolution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Sum of numbers from 0 to n
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        // Compute actual sum of elements in nums
        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        // The difference is the missing number
        return expectedSum - actualSum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1}; // Example input: missing number is 2

    NaiveSolution naiveSol;
    FormulaSolution formulaSol;

    // Call both approaches
    int naiveResult = naiveSol.missingNumber(nums);
    int formulaResult = formulaSol.missingNumber(nums);

    // Output results
    cout << "Naive Approach (Sorted) Missing Number: " << naiveResult << endl;
    cout << "Formula Approach (Optimized) Missing Number: " << formulaResult << endl;

    return 0;
}
