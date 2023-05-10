#include<iostream>
#include<vector>
#include<set>


int doubleslice(std::vector<int> &vec) {

std::vector<int> K1(vec.size(),0);
std::vector<int> K2(vec.size(),0);

  for(int i = 1; i < vec.size()-1; i++){
    K1[i] = std::max(K1[i-1] + vec[i], 0);
  }
  for(int i = vec.size()-2; i > 0; i--){
    K2[i] = std::max(K2[i+1]+vec[i], 0);
  }

  int max = 0;

  for(int i = 1; i < vec.size()-1; i++){
    max = std::max(max, K1[i-1]+K2[i+1]);
  }

  return max;
}

int main(){
    std::vector<int>vec={3,2,6,-1,4,5,-1,2 };
std::cout<<doubleslice(vec);
    return 0;
}