// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
int solution(std::vector<int> &A) {
 
    std::vector<bool> check(A.size(), false);
  
        
    for (unsigned int index = 0; index < A.size(); index++) {
          
           
        if (A[index] > (int)A.size()) {
            return 0;
        }
        if (check[A[index]-1]) {
            
            return 0;
        }
        check[A[index]-1] = true;
    }
    for (unsigned int index = 0; index < A.size(); index++) {
        if (!check[index]) {
            return 0;
        }
    }
    return 1;
}
