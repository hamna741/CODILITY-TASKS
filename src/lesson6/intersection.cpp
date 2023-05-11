#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
#include <algorithm>

int cars(std::vector<int> &A){
 
    std::vector<int> left(A.size()), right(A.size());
    for (int i = 0; i < A.size(); i++) {
        left[i] = i - A[i];
        right[i] = i + A[i];
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int intersections = 0, circle2 = 0;
    for (int circle1 = 0; circle1 < A.size(); circle1++) {
        while (circle2 < A.size() && right[circle1] >= left[circle2]) {
            intersections += circle2- circle1;
            circle2++;
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