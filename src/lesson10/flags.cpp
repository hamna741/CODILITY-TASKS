// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
int solution(std::vector<int> &A) {
      
  std::vector<int> peaks;

    for (int index = 1; index < A.size()- 1; index++) {
        if (A[index] > A[index-1] && A[index] > A[index+1]) {
            peaks.push_back(index);
        }
    }
   int maxFlags = 0;
    int numPeaks = peaks.size();
    
    for (int flags = 1; flags <= numPeaks; flags++) {
        int prevPeak = peaks.at(0);
        int setFlags = 1;
        
        for (int i = 1; i < numPeaks && setFlags < flags; i++) {
            if (peaks.at(i) - prevPeak >= flags) {
                prevPeak = peaks.at(i);
                setFlags++;
            }
        }
        
        if (setFlags == flags) {
            maxFlags = flags;
        } else {
            break;
        }
    }
    
    return maxFlags;
}