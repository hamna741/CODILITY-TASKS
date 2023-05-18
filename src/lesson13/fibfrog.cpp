// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>
std::vector<int> fibonacci(int MaxNum)
{
    if (MaxNum == 0)
        return std::vector<int>(1, 0);
    std::vector<int> fib(2, 0);
    fib[1] = 1;
    for (int i = 2; fib[fib.size() - 1] + fib[fib.size() - 2] <= MaxNum; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    return fib;
}
int solution(std::vector<int> &A)
{
    int N = A.size();
    if (N == 0)
        return 1;
    A.push_back(1);
    N++;
    std::vector<int> fib = fibonacci(N);

    std::vector<int> jumps(N, 1000000);

    for (auto i : fib)
        if (i - 1 >= 0 && A[i - 1])
            jumps[i - 1] = 1;

    for (int pos = 0; pos < N; pos++)
    {
        if (A[pos] == 0)
            continue;

        for (int index = fib.size() - 1; index >= 0; index--)
        {
            if (pos + fib[index] < N && A[pos + fib[index]])
            {
                jumps[pos + fib[index]] = std::min(jumps[pos] + 1, jumps[pos + fib[index]]);
            }
        }
    }
    if (jumps[N - 1] != 1000000)
    {
        return jumps[N - 1];
    }
    return -1;
}

int main()
{
    std::vector<int> A = {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
    std::cout << solution(A) << std::endl;
}