#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
std::vector<int> genome(std::string s,std::vector<int> &p,std::vector<int> &Q){
std::vector<int> result;
    int N = s.size(), M = p.size();

    for (int i = 0; i < M; i++) {
        int start = p[i], end = Q[i];
        int min_impact_factor = 4;

        for (int j = p[i]; j <= Q[i]; j++) {
            int impact_factor;
            if (s[j]=='A') 
               
                    impact_factor = 1;
                   if (s[j]=='C')
                    impact_factor = 2;
                    if (s[j]=='G')
                    impact_factor = 3;
                   if (s[j]=='T')
                    impact_factor = 4;
    
        
            if (impact_factor < min_impact_factor) {
                min_impact_factor = impact_factor;
        
        }
        }

        result.push_back(min_impact_factor);
    }

    return result;
}

int main(int argc, char* argv[]){
 

std:: vector<int> P={2,5,0};
std:: vector<int> Q={4,5,6};
std::string S="CAGCCTA";
for(auto val:genome(S,P,Q))
std::cout<<val<<" ";
std::cout<<std::endl;
  
    return 0;

}


