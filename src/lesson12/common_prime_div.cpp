#include<iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

 int gcd(int a, int b){
        if(b == 0) 
            return a;
        else 
             return gcd(b, a % b);
    }
bool isdiv(int num, int g){
        
        if(num == 1) 
        return true;
        else if(g == 1) 
        return false;
        
        else {
            g = gcd(g, num);
            num = num/g;
        
            return isdiv(num, g);
        }
    }

 int prime_diviors(std::vector<int>A, std::vector<int>B) {
        int count = 0;
        for(int index = 0; index < A.size(); index++){
            if(A[index] == B[index]) 
                count++;
            else if(A[index] == 1 || B[index] == 1)
                 continue;
            else{
                int GCD = gcd(A[index], B[index]);
                
                if(GCD == 1) 
                    continue;
                
                int newA = A[index]/GCD;
                int newB = B[index]/GCD;
                
                if(isdiv(newA, GCD) && isdiv(newB, GCD)) 
                count++;
            } 
        }
        
        return count;
    }
    
int main(){
    std::vector<int> A = {15, 10, 3};
    std::vector<int> B = {75, 30, 5};
    int count = prime_diviors(A, B);
    std::cout<<count<<" pair(s) have common prime diviors"<<std::endl;
}