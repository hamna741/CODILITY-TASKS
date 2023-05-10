#include <vector>
#include<iostream>


std::vector<int> semiprime(int N, std::vector<int> &P, std::vector<int> &Q) {
    std::vector<int> primes;
    std::vector<int> semiprimes(N+1, 0);

    for (int i = 2; i <= N; i++) {
        if (semiprimes[i] == 0) {
            primes.push_back(i);
            for (int j = i*i; j <= N; j += i) {
                semiprimes[j] = 1;
            }
        }
    }


    std::vector<int> semiprime_count(N+1, 0);
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int semiprime = primes[i] * primes[j];
            if (semiprime > N) 
            break;
            semiprime_count[semiprime] = 1;
        }
    }

   std:: vector<int> semiprime_prefix_sum(N+1, 0);
    for (int i = 1; i <= N; i++) {
        semiprime_prefix_sum[i] = semiprime_prefix_sum[i-1] + semiprime_count[i];
    }

  
   std:: vector<int> results;
    for (int i = 0; i < P.size(); i++) {
        int result = semiprime_prefix_sum[Q[i]] - semiprime_prefix_sum[P[i]-1];
        results.push_back(result);
    }

    return results;
}


int main(int argc, char* argv[]){
    int N=26;
    std::vector<int>P{1,4,16};
    std::vector<int>Q{26,10,20};

std:: vector<int> vec;
for(auto val:semiprime(N,P,Q))
std::cout<<val;


    
    return 0;

}
