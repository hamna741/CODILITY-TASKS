// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
#include <algorithm>
#include<iostream>
int solution(std::vector<int> &A) {
     std::sort(A.begin(), A.end());
   
    int left = 0, right = A.size() - 1;
    int min_abs_sum = std::abs(A[left] + A[right]);
    while (left <= right) {
        int sum = A[left] + A[right];
        min_abs_sum = std::min(min_abs_sum, std::abs(sum));
        if (sum < 0) { //num at right is bigger
            ++left;
        } else {
            --right;
        }
    }
    return min_abs_sum;
}
int main(){
    std::vector<int>A={1,4,-3};
    std::cout<<solution(A)<<std::endl;
}