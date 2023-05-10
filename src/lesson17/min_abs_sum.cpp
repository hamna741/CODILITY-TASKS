#include<iostream>
#include <vector>
#include <set> 
#include<math.h>



int min_sum(std::vector<int> &vec) {
   
    if (vec.size() == 0) return 0;

    std::set<int> sum, tmpSums;        
    sum.insert(abs(vec[0]));
    for (auto it = vec.begin()+1 ; it != vec.end(); ++it)
    {        
        for (auto val : sum)
        {
            tmpSums.insert(abs(val + abs(*it)));
            tmpSums.insert(abs(val - abs(*it)));            
        }
        sum = tmpSums;
        tmpSums.clear();
    }

  return *sum.begin();
}

int main(int argc, char* argv[]){
      std::vector<int> vec;
    if(argc<2){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{
          for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
    }
   
     std::cout<<"MINIMUM ABSOLUTE SUM = "<<min_sum(vec)<<std::endl;
}

}