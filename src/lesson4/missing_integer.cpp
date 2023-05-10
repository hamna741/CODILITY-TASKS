#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
int missing(std::vector<int> &vec){

std::sort(vec.begin(), vec.end());
 
int index=1;
for(auto elm:vec){

if(elm!=index)
return index;
else
index++;
}
return 0;
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

    std::cout<<"MISSING NUMBER= "<<missing(vec)<<std::endl;
    }
    return 0;

}


