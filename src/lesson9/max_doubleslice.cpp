#include<iostream>
#include<vector>

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
   
std::vector<int> K1(A.size(),0);
std::vector<int> K2(A.size(),0);

  for(unsigned int i = 1; i < A.size()-1; i++){
    K1[i] = std::max(K1[i-1] + A[i], 0);
  }
  for(unsigned int i = A.size()-2; i > 0; i--){
    K2[i] = std::max(K2[i+1]+A[i], 0);
  }

  int max = 0;

  for(unsigned int i = 1; i < A.size()-1; i++){
    max = std::max(max, K1[i-1]+K2[i+1]);
  }

  return max;
}
int main(){
    std::vector<int>A={3,2,6,-1,4,5,-1,2};
    std::cout<<solution(A)<<std::endl;
}