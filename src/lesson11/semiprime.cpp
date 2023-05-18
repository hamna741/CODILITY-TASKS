#include <set>
#include <iterator>
#include <vector>
#include <iostream>
std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q)
{

    std::vector<int> result(P.size(), 0);
    if (N < 4)
    {
        return result; // 4 is the smallest possible semiprime
    }

    std::vector<int> primeN(N / 2 + 1, 1); // Initially all true
    primeN[0] = 0;
    primeN[1] = 0;

    // Sieve of Eratosthenes to find all prime numbers
    for (int index = 2; (index * index) <= N / 2; index++)
    {
        for (int index2 = index * 2; index2 <= N / 2; index2 = index2 + index)
        {
            if (primeN[index2] == 1)
            {                       // multiple of i
                primeN[index2] = 0; // not prime
            }
        }
    }

    std::vector<int> primevec;
    for (int index = 0; index < N / 2 + 1; index++)
    {
        if (primeN[index] == 1)
        {
            primevec.push_back(index);
        }
    }

    std::set<int> semiprime_vec;
    for (int i = 0; i < primevec.size(); i++)
    {
        if (primevec[i] * primevec[i] > N)
        {
            break;
        }
        for (int j = i; j < primevec.size(); j++)
        {
            if (primevec[i] * primevec[j] <= N)
            {
                semiprime_vec.emplace(primevec[i] * primevec[j]); // semiprime numbers upto N
            }
        }
    }

    std::vector<int> accum(N, 0);
    std::set<int>::iterator it = semiprime_vec.begin();
    int count_semiprime = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == *it)
        {
            count_semiprime++;
            if (it != semiprime_vec.end())
            {
                std::advance(it, 1);
            }
        }
        accum[i - 1] = count_semiprime; // accumalted sum of semiprime numbers (for snumbers in P to Q range)
    }

    int starting_point = 0;

    for (unsigned int i = 0; i < P.size(); i++)
    {
        if (P[i] == 1)
            starting_point = 0; // to start from index 0
        else
            starting_point = P[i] - 2;
        result[i] = accum[Q[i] - 1] - accum[starting_point];
    }

    return result;
}

int main()
{
    int N = 26;
    std::vector<int> P = {1, 4, 16};
    std::vector<int> Q = {26, 10, 20};
    for (auto val : solution(N, P, Q))
        std::cout << val;
    std::cout << std::endl;
}