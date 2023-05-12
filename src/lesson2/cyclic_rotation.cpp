
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<iostream>
#include<vector>
std::vector<int> solution(std::vector<int> &A, int K) {
     if (K < 0) {
        return A;
    }
if (A.empty()) {
        return A;
    }
 
    for (int cycle = 0; cycle < K; cycle++) {
   int last = A[A.size() - 1];
    for (int index =A.size() - 2; index >= 0; index--) {
        A[index + 1] = A[index];
    }
 
    A[0] = last;
}

return A;
}