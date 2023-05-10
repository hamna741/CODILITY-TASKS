#include<iostream>
#include<vector>
#include<map>

int odd(std::vector<int> &vec){

std::map<int, int>occurance_count;
for (int index = 0; index< vec.size(); index++)
{
    occurance_count[vec[index]]++;
}
for ( auto it = occurance_count.begin(); it != occurance_count.end(); ++it)
{
    if (it->second%2==1)
    {
        return it->first;
    }
    
}
return -1;
}

int main(int argc, char* argv[]){
    if (argc<1)
{
   std::cout<<"INVALID INPUT"<<std::endl;
   return 1;
}
else{      
   std:: vector<int> vec;
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
    }

    
    std::cout<<"odd entry= "<<odd(vec)<<std::endl;
    }

return 0;


    }

