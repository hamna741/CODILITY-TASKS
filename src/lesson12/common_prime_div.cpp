// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
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

 int solution(std::vector<int> &A, std::vector<int> &B) {
        int count = 0;
        for(unsigned int index = 0; index < A.size(); index++){
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