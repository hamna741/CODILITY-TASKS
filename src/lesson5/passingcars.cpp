#include<vector>
#include<iostream>
int solution(std::vector<int> &A) {
    int east = 0, pairs = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0) {
            east++;
        } else {
            pairs += east;
            if (pairs > 1000000000) {
                return -1;
            }
        }
    }
    return pairs;
}
int main(){
    std::vector<int>A={0,1,0,1,1};
    std::cout<<solution(A);
}