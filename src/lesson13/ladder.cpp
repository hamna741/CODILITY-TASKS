// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

#include<vector>
std::vector<int> solution(std::vector<int> &A, std::vector<int> &B) {
    int max_rungs = 0;
    for (unsigned int i = 0; i < A.size(); i++) {
        max_rungs = std::max(max_rungs, A[i]);
    }
    int max_power = 0;
    for (unsigned int i = 0; i < B.size(); i++) {
        max_power =std:: max(max_power, B[i]);
    }
    int mod = pow(2, max_power);
    std::vector<int> fib(max_rungs+1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= max_rungs; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % mod; //corresponding to one step and two steps
       
    }
 
    std::vector<int> result;
    for (unsigned int i = 0; i < A.size(); i++) {
      
        result.push_back(fib[A[i]] % (int) pow(2, B[i]));
    }
  
   
    return result;
}
