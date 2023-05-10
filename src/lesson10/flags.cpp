#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
int sum(std::vector<int> &vec){
 int N = vec.size();
 
  std::vector<int> peaks;

    for (int index = 1; index < vec.size()- 1; index++) {
        if (vec[index] > vec[index-1] && vec[index] > vec[index+1]) {
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



int main(int argc, char* argv[]){
     if(argc<1){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{

std:: vector<int> vec;

    for (int i = 0; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
       
    }
 int max_flags = sum(vec);
    std::cout<<"NUMBER OF FLAGS: "<<max_flags<<std::endl;
    }
    return 0;

}


