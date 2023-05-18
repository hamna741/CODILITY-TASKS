// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <iostream>
// int solution(std::vector<int> &A) //1 5 2 1 4 0
// {
//     std::vector<int> left(A.size()), right(A.size());
//     for (int i = 0; i < A.size(); i++)
//     {
//         left[i] = i - A[i];  //-1 -4 0 2 0 5
//         right[i] = i + A[i]; //1 5 4 4 8 5
//     }
//     std::sort(left.begin(), left.end());  //-4 -1 0 0 2 5
//     std::sort(right.begin(), right.end()); //1 4 4 5 5 8
//     int intersections = 0, circle2 = 0;
//     for (int circle1 = 0; circle1 < A.size(); circle1++)
//     {
//         for (circle2 < A.size() && right[circle1] >= left[circle2];circle2++;)
//         {
//             intersections += circle2 - circle1;

//             if (intersections > 10000000)
//             {
//                 return -1;
//             }
//         }
//     }
//     return intersections;
// }

int solution(std::vector<int> &A)
{
    std::vector<long long> left(A.size()), right(A.size());
    for (long long i = 0; i < A.size(); i++)
    {
        left[i] = i - static_cast<long long>(A[i]);
        right[i] = i + static_cast<long long>(A[i]);
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int intersections = 0;
    long circleCount = 0;
    long leftPoint = 0;
    long rightPoint = 0;

    while (leftPoint < A.size())
    {
        if (left[leftPoint] <= right[rightPoint])
        {
            intersections += circleCount;
            if (intersections > 10000000)
                return -1;

            circleCount++;
            leftPoint++;
        }
        else
        {
            circleCount--;
            rightPoint++;
        }
    }

    return intersections;
}
int main()
{
    std::vector<int> A = {1, 5, 2, 1, 4, 0};
    std::cout << solution(A) << std::endl;
}