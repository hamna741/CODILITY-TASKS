#include<iostream>
int jumps(int x, int y, int d){
    int current_position=x;
    int jump_number=1;
if (x==y){
    return 0;
}
else{
    while(current_position<y){
    current_position=x+(jump_number*d);
    jump_number++;}
}
return jump_number-1;
    }

int main(int argc, char* argv[]){
    if(argc!=4){
        std::cout<<"INVALID INPUT!!";
        return 1;
    }
    else{
int x=atoi(argv[1]);
int y=atoi(argv[2]);
int d=atoi(argv[3]);
std::cout<<"NUMBER OF JUMPS= " <<jumps(x,y,d)<<std::endl;

    }
}