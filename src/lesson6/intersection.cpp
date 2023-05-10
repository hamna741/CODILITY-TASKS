#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
#include <algorithm>

int cars(std::vector<int> &A){
 int n = A.size();
    std::vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        left[i] = i - A[i];
        right[i] = i + A[i];
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int intersections = 0, j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && right[i] >= left[j]) {
            intersections += j - i;
            j++;
            if (intersections > 10000000) {
                return -1;
            }
        }
    }
    return intersections;
}

int main(int argc, char* argv[]){
     if(argc<2){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{

std:: vector<int> vec;
int counters=atoi(argv[1]);
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
    }

    std::cout<<"NUMBER OF PAIRS: "<<cars(vec)<<std::endl;
    }
    return 0;

}