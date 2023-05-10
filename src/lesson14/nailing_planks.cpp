#include <iostream>
#include <numeric>
#include <vector>


    bool isNailed(int nail, const std:: vector<int> &A, const std::vector<int> &B, const std::vector<int> &C)
    {
        const int N = A.size();
        const int M = C.size();

        // This also accounts for duplicate nails, essentially ignores them
        std::vector<int> nails(2*M+1, 0);
        
        for (int i = 0; i < nail; i++)
        {
            nails[C[i]] = 1;
        }

        // Create the partial sums based on the nails present
        std::partial_sum(nails.begin(), nails.end(), nails.begin());

        bool nailed = true;
        for (int i = 0; (i < N) && nailed; i++)
        {
            nailed = (nails[B[i]] - nails[A[i]-1]) > 0;
        }

        return nailed;
    }

    // The standard binary search mechanism
    int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
    {
        int minNails = 1;
        int maxNails = C.size();

        int result = -1;
        while (minNails <= maxNails)
        {
            int mid = (minNails + maxNails) / 2;
            if (isNailed(mid, A, B, C))
            {
                maxNails = mid - 1;
                result = mid;
            } else {
                minNails = mid + 1;
            }
        }

        return result;
    }
int main(){
std::vector<int> A={1,4,5,8};
std::vector<int> B={4,5,9,10};
std::vector<int> C={4,6,7,10,2};
std::vector<int> nails(2*A.size()+1, 0);
std::cout<<nails.size()<<std::endl;
 for (int i = 0; i <3; i++)
        {
            nails[C[i]] = 1;
        }
for(auto val:nails)
std::cout<<val;
std::cout<<std::endl;
std::partial_sum(nails.begin(), nails.end(), nails.begin());
std::cout<<nails[9]<<std::endl;
for(auto val:nails)
std::cout<<val;
//std::cout<<solution(A,B,C)<<std::endl;
}