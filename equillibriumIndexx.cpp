#include <iostream>
#include <vector>
using namespace std;

int equilibriumIndex(vector<int>& A) {
    int totalSum = 0;
    for (int num : A) {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < A.size(); i++) {
        int rightSum = totalSum - leftSum - A[i];
        if (leftSum == rightSum) {
            cout<<i;
            return i;
        }
        leftSum += A[i];
    }

    return -1;
}

int main (){
    vector<int> arr = {1,3,3,5,5,2};
    equilibriumIndex(arr);
    
}