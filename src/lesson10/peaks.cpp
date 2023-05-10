

#include<iostream>
#include<vector>

int sum(std::vector<int> &vec){
    std::vector<int> peaks;

    for (int index = 1; index < vec.size()- 1; index++) {
        if (vec[index] > vec[index-1] && vec[index] > vec[index+1]) {
            peaks.push_back(index);
        }

    }

    
    for(int size = 1; size <= vec.size(); size++){
      if(vec.size() % size != 0) 
      continue; //equal size of subarrays
      int g_count = 0;
      int groups = vec.size()/size;
      bool ok = true;
     
      for(int p_index=0;p_index<peaks.size();p_index++){
       
        if(peaks[p_index]/size > g_count){
          ok = false;
          break;
        }
        if(peaks[p_index]/size == g_count) 
        g_count++;
   
      }
      if(g_count != groups) ok = false;
      if(ok) return groups;
    }
    return 0;
  }


int main(int argc, char* argv[]){
     if(argc<1){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{

std:: vector<int> vec;

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
       
    }
 int max_arr= sum(vec);
;
    std::cout<<"NUMBER OF SUBARRAYS "<<max_arr<<std::endl;
    }
    return 0;

}
    