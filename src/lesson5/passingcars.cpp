#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
int cars(std::vector<int> &vec){
    int pair_count=0;
for(int index =0; index<vec.size();index++){
    for(int index2=index;index2<vec.size();index2++){
        if(vec[index]==0 &&vec[index2]==1)
        { 
            pair_count++;}
       
    }
   
}
if(pair_count>10000000000)
return -1;
return pair_count;
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


