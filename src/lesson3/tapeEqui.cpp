#include<iostream>
#include<cmath>
#include <algorithm>
#include<climits>
#include<vector>


int Tape(std::vector<int> &A){
   int sum = 0;
   int mindif;
   int diff;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    
    int leftSum = 0;
    int rightSum = sum;
    int minDiff = INT_MAX;
    
    for (int i = 0; i < A.size() - 1; i++) {
        leftSum += A[i];
        
        rightSum -= A[i];
        
         diff = abs(leftSum - rightSum);
         
         minDiff = std::min(minDiff, diff);
    }
  
    return minDiff;
}

int main(int argc, char* argv[]){
    if(argc<2){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{

std:: vector<int> vec;
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
    }
   
    int minDiff = Tape(vec);
    std::cout<<" min difference = "<<minDiff<<std::endl;
  
    return 0;
}
}