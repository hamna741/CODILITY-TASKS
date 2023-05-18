#include<vector>
#include <algorithm>
#include<numeric>
#include<iostream>
int solution(int K, int M, std::vector<int> &A) {
    int N = A.size();
    int max_elem = *max_element(A.begin(), A.end());
    int sum_elems = std::accumulate(A.begin(), A.end(), 0);
    int left = max_elem; //minium possible sum
    int right = sum_elems;
    int result = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        int num_of_blocks = 1;
        int block_sum = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > mid) {
                num_of_blocks = K + 1;
                break;
            }
            if (block_sum + A[i] > mid) {
                num_of_blocks++;
                block_sum = A[i];
            } else {
                block_sum += A[i];
            }
        }
        if (num_of_blocks <= K) {
            result = mid; 
            right = mid - 1; //dec max sum
        } else {
            left = mid + 1;
        }
    }
    return result;
}
int main(){
    int k=3;
    int m =5;
 std::vector<int>P={2,1,5,1,2,2,2};
 std::cout<<solution(k,m,P);
}

