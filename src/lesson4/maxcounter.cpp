#include<iostream>
#include<vector>
int maxcount(std::vector<int> &vec,int N){
   int counter[N]={0};
   int max=0;

 
for(int index=0;index<vec.size();index++){
  
if(vec[index]<N){

counter[vec[index]]++;
}
else{
    
    for(int index=0; index<N;index++)
    if(counter[index]>max)
    max=counter[index];
    for(int index=0; index<N;index++)
    counter[index]=max;
}
for(int i=0; i<N;i++)
std::cout<<counter[i];
std::cout<<std::endl;
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
    for (int i = 2; i < argc; i++) {
        int num = atoi(argv[i]); 
        vec.push_back(num); 
    }
    maxcount(vec,counters);
    }
    return 0;
}