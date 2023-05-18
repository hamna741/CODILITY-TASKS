// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <climits>
#include <vector>
#include <iostream>
int solution(std::vector<int> &A)
{

    std::vector<long> max_result(A.size(), INT_MIN);
    max_result[0] = A[0];
    for (int index1 = 1; index1 < (int)A.size(); index1++)
    {
        for (int index2 = 1; index2 < 7; index2++)
        {
            if (index1 - index2 >= 0)                                                                       // not to excede 6
                max_result[index1] = std::max(max_result[index1], A[index1] + max_result[index1 - index2]); // index1-index2 -->next move
        }
    }
    return max_result[A.size() - 1];
}
int main()
{
    std::vector<int> A = {1, -2, 0, 9, -1, -2};
    std::cout << solution(A) << std::endl;
}