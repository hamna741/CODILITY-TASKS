#include <vector>
int solution(std::vector<int> &A) {
    int result = 0;
   for (int index=0; index<A.size();index++){ 
     
     result ^= A[index];   //a^a=0 a^0 = a
     }
   return result;
}