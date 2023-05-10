
#include<vector>
#include<iostream>



std::vector<int> fibonacci(int MaxNum) {
    if (MaxNum == 0)
        return std::vector<int>(1, 0);
    std::vector<int> fib(2, 0);
    fib[1] = 1;
    for (int i = 2; fib[fib.size()-1] + fib[fib.size() - 2] <= MaxNum; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    //       for(auto val:fib)
    // std::cout<<val;
    // std::cout<<std::endl;
    return fib;
}

int frog(std::vector<int>& A) {
    int N = A.size();
    if (N == 0)
        return 1;
    A.push_back(1);
    N++;
   std:: vector<int> fib = fibonacci(N);
   
   std:: vector<int> jumps(N, 1000000);
    
    for (auto i : fib)
        if (i - 1 >= 0 && A[i-1])
            jumps[i-1] = 1;
    
    for (int pos = 0; pos < N; pos++) {
        if (A[pos] == 0)
            continue;

        for (int i = fib.size()-1; i >= 0; i--) {
            if (pos + fib[i] < N && A[pos + fib[i]]) {
                jumps[pos + fib[i]] = std::min(jumps[pos]+1, jumps[pos + fib[i]]);
            }
        }
    }
    if (jumps[N - 1] != 1000000) {
        return jumps[N - 1];
    }
    return -1;
}

int main() {
    std::vector<int> A = {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
    int min_jumps = frog(A);
    std::cout << "Minimum number of jumps: " << min_jumps << std::endl;
    return 0;
}