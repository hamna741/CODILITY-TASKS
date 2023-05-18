// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <climits>
#include <vector>
#include <iostream>
int solution(std::vector<int> &A)
{
    int sum = 0;

    int diff;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }

    int leftSum = 0;
    int rightSum = sum;
    int minDiff = INT_MAX;

    for (unsigned int i = 0; i < A.size() - 1; i++)
    {
        leftSum += A[i];

        rightSum -= A[i];

        diff = abs(leftSum - rightSum);

        minDiff = std::min(minDiff, diff);
    }

    return minDiff;
}
int main()
{
    std::vector<int> A = {3, 2, 1, 4, 3};
    std::cout << solution(A) << std::endl;
}