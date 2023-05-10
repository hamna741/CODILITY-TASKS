#include<iostream>
#include<vector>
int missing(std::vector<int> &vec){
        //missing(arr);
int x1 = vec[0];
  int x2 = 1;

  for (int index = 1; index < vec.size()-1; index++)
    x1 = x1 ^ vec[index];

  for (int index = 2; index <=  vec.size()-1+ 1; index++) //arr including missing num
    x2 = x2 ^ index;
 if ((x1 ^ x2)==vec.back())
    return 1;
else
return 0;
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

    if (missing(vec))
    std::cout<<"ARRAY IS A PERMUTATION"<<std::endl;
    
    else
     std::cout<<"NOT A PERMUTATION!!"<<std::endl;
    }
    return 0;
}