#include<iostream>
#include<vector>
int missing(std::vector<int> &vec){
       
int x1 = vec[0];
  int x2 = 1;

  for (int index = 1; index < vec.size()-1; index++)
    x1 = x1 ^ vec[index];

  for (int index = 2; index <=  vec.size()-1+ 1; index++) 
    x2 = x2 ^ index;

  return (x1 ^ x2);
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

    
    std::cout<<"MISSING NUMBER = "<<missing(vec)<<std::endl;
    }
    
    return 0;
}