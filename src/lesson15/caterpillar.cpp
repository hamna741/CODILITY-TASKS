
#include <algorithm>
#include <iostream>
#include<vector>
#include <cmath>

int abs_sum(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    int N = A.size();
    int left = 0, right = N - 1;
    int min_abs_sum = std::abs(A[left] + A[right]);
    while (left <= right) {
        int sum = A[left] + A[right];
        min_abs_sum = std::min(min_abs_sum, std::abs(sum));
        if (sum < 0) {
            ++left;
        } else {
            --right;
        }
    }
    return min_abs_sum;
}

int main(){
    std::vector<int> vec={-8,4,5,-10,3};
    std::cout<<abs_sum(vec);
}