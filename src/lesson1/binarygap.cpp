#include<iostream>
#include <bitset>
#include <cstdlib>
int main(int argc, char* argv[]){
    if(argc!=2){
        std::cout<<"enter number!!";
        return 1;
    }
    else{

   
    std::bitset<32> binary(atoi(argv[1])); //binary representation
    int max_zeros = 0;
    int zero_count = 0;
    bool zero_flag = false;
    std::cout<<"BINARY OF "<<atoi(argv[1])<<" " <<binary<<std::endl;
    for (int i = 0; i < 32; i++) {
        if (binary.test(i)) {  //'1'
            if (zero_flag) { // a gap
                max_zeros = std::max(max_zeros, zero_count);
                zero_count = 0; // reset the counter
            } else {
                zero_flag = true;
            }
        } else { //'0'
            if (zero_flag) {
                zero_count++;
            }
        }
    }
    std::cout<<"NUMBER OF CONSECTIVE ZEROS: "<<max_zeros<<std::endl;
    return 0;
}
}