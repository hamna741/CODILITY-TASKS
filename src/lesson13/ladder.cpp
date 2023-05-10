#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    int max_rungs = 0;
    for (int i = 0; i < A.size(); i++) {
        max_rungs = max(max_rungs, A[i]);
    }
    int max_power = 0;
    for (int i = 0; i < B.size(); i++) {
        max_power = max(max_power, B[i]);
    }
    int mod = pow(2, max_power);
    vector<int> fib(max_rungs+1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= max_rungs; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
        std::cout<<fib[i];
    }
    std::cout<<std::endl;
    vector<int> result;
    for (int i = 0; i < A.size(); i++) {
        std::cout<<fib[A[i]];
        result.push_back(fib[A[i]] % (int) pow(2, B[i]));
    }
    std::cout<<std::endl;
    for(auto val: result)
    std::cout<<val;
    return result;
}
int main(){
    std::vector<int> vec1{4,4,5,5,1};
    std::vector<int> vec2{3,2,4,3,1} ;
    solution(vec1,vec2);
    return 0;
}