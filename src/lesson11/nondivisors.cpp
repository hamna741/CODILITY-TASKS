#include <vector>
#include <unordered_map>
#include <algorithm>
int divisors(int num, std::unordered_map<int, int>& occur_count) {
    int count = 0;
    
    for(int div = 1;div * div <= num;div++) {
        if (num % div == 0) { 
            if (occur_count[num/div] > 0) {
                count += occur_count[num/div];
            }
            if (num/div != div && occur_count[div] > 0) {
                count += occur_count[div];
            }
        }
        
    }
    return count;
}
std::vector<int> solution(std::vector<int>& A) {
  
    if (A.size() < 1 || A.size() > 50000) throw std::invalid_argument("Bad input");

    std::unordered_map<int, int> occur_count;
    std::vector<int> keys;
    for (int i = 0; i < A.size(); ++i) {
        
        int uniqueCount = occur_count[A[i]];
        if (uniqueCount > 0) {
            occur_count[A[i]] = uniqueCount + 1;
        } else {
            occur_count[A[i]] = 1;
            keys.push_back(A[i]);
        }
    }

    std::sort(keys.begin(), keys.end());

    for (int index = keys.size() - 1; index >= 0; --index) {
        int num = keys[index];
        int divisorCount = divisors(num, occur_count);

        int nonDivisorCount = A.size() - divisorCount;
        occur_count[num] = nonDivisorCount;
    }

    for (int index = 0; index < A.size(); ++index) {
        int num = A[index];
        A[index] = occur_count[num];
    }
    return A;
}


