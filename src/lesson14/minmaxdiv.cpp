#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int K, int M, vector<int> &A) {
    int N = A.size();
    int max_sum = M * N; 
    int min_sum = 1; 
    while (min_sum < max_sum) {
        int mid_sum = (min_sum + max_sum) / 2;
        int count = 1; 
        int curr_sum = 0; 
        for (int i = 0; i < N; i++) {
            if (curr_sum + A[i] > mid_sum) {
                count++; 
                curr_sum = A[i];
            } else {
                curr_sum += A[i];
            }
        }
        if (count <= K) {
            max_sum = mid_sum; 
        } else {
            min_sum = mid_sum + 1; 
        }
    }
    return min_sum;
}
int main() {
    vector<int> A = {2, 1, 5, 1, 2, 2, 2};
    int K = 3;
    int M = 5;

    int result = solution(K, M, A);

    cout << result << endl;

    return 0;
}