#include<iostream>

int main(int argc, char* argv[]){
 //int A[4]={1,2,3,4};
if (argc<2)
{
   std::cout<<"INVALID INPUT"<<std::endl;
   return 1;
}
else{
    if (argc==2){
        std::cout<<atoi(argv[1])<<std::endl;

    }
else{
 int A[argc - 2];

    for(int i = 2; i < argc; i++) {
        A[i-2 ] = atoi(argv[i]); 
    }
int k=atoi(argv[1]);
    int temp;
    
for (int rot=0;rot<k;rot++){
    temp=A[0];
for (int index =0; index<sizeof(A)/4 ;index++){
    if(index!=(sizeof(A)/4)-1){
    A[index]=A[index+1];
    }
    else
    A[index]=temp;
}
}

for (int i =0;i<sizeof(A)/4;i++)
std::cout<<A[i]<<" ";
}
return 0;
}
}