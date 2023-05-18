// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> solution(int N, std::vector<int> &A)
{
    std::vector<int> counters(N, 0);
    int current_max = 0;
    int last_max = 0;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        for (auto val : counters)
            std::cout << val;
        std::cout << std::endl;
        if (A[i] >= 1 && A[i] <= N)
        {
            counters[A[i] - 1]++;
            current_max = std::max(current_max, counters[A[i] - 1]);
        }
        else if (A[i] == N + 1)
        {
            if (current_max > last_max)
            {
                std::fill(counters.begin(), counters.end(), current_max);
                last_max = current_max;
            }
        }
    }

    return counters;
}
int main()
{
    int N = 5;
    std::vector<int> A = {3, 4, 4, 6, 1, 4, 4, 6};
    for (auto val : solution(N, A))
        std::cout << val;
    std::cout << std::endl;
}