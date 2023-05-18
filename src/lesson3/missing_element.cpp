// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <algorithm>
#include <vector>
int solution(std::vector<int> &A)
{

    if (A.size() == 0)
    {
        return 1;
    }

    std::sort(A.begin(), A.end());

    int num = 1;

    for (unsigned int i = 0; i < A.size(); i++, num++)
    {
        if (A[i] != num)
        {
            return num;
        }
    }

    return num;
}

int main()
{
    std::vector<int> A = {2, 3, 1, 5};
    std::cout << solution(A) << std::endl;
}