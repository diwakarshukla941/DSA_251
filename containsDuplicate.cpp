#include <iostream>              // For input and output (cin, cout)
#include <vector>                // For using vector container
#include <unordered_set>         // For using unordered_set
using namespace std;             // So we don't have to write std:: everywhere

// Solution class containing the function to check for duplicates
class Solution {
public:
    // Function that returns true if any number appears more than once
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;  // Declare an empty set to store unique numbers

        // Loop through each number in the nums vector
        for(int i = 0; i < nums.size(); i++) {

            // Check if current number already exists in the set
            if(numSet.find(nums[i]) != numSet.end()) {
                // If found, it's a duplicate — return true
                return true;
            }

            // If not found, insert the number into the set
            numSet.insert(nums[i]);
        }

        // If loop completes and no duplicate found, return false
        return false;
    }
};

int main() {
    Solution sol;  // Create an object of the Solution class

    // Input vector with integers
    vector<int> nums = {1, 2, 3, 4, 1};

    // Call the containsDuplicate function and display result
    if(sol.containsDuplicate(nums)) {
        cout << "Contains duplicate" << endl;
    } else {
        cout << "No duplicate" << endl;
    }

    return 0; // Exit program
}
