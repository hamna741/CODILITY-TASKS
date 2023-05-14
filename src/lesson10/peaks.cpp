// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
int solution(std::vector<int> &A) {
     std::vector<int> peaks;

    for (unsigned int index = 1; index < A.size()- 1; index++) {
        if (A[index] > A[index-1] && A[index] > A[index+1]) {
            peaks.push_back(index);
        }

    }

    
    for(unsigned int size = 1; size <= A.size(); size++){
      if(A.size() % size != 0) 
      continue; //equal size of subarrays
      int g_count = 0;
      int groups = A.size()/size;
      bool ok = true;
     
      for(unsigned int p_index=0;p_index<peaks.size();p_index++){
       
        if(peaks[p_index]/size > g_count){
          ok = false;
          break;
        }
        if(peaks[p_index]/size == g_count) 
        g_count++;
   
      }
      if(g_count != groups) ok = false;
      if(ok) return groups;
    }
    return 0;}