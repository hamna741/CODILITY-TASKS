// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <iostream>
int solution(std::vector<int> &A)
{

    std::sort(A.begin(), A.end());

    int num = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= 0)
        {

            continue;
        }
        if (A[i] == num)
        {

            num++;
        }
        else if (A[i] > num)
        {
            return num;
        }
    }
}
int main()
{
    std::vector<int> A = {1, 3, 6, 4, 1, 2};
    std::cout << solution(A) << std::endl;
}