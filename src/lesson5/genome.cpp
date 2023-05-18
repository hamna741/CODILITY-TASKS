// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <string>
#include <iostream>

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
std::vector<int> solution(std::string s, std::vector<int> &p, std::vector<int> &Q)
{
    std::vector<int> result;
    int N = s.size(), M = p.size();
    std::vector<int> countA(N, 0);
    std::vector<int> countC(N, 0);
    std::vector<int> countG(N, 0);
    std::vector<int> countT(N, 0);
    for (int index = 1; index < N; index++)
    {
        countA[index] = countA[index - 1] + (s[index - 1] == 'A');
        countC[index] = countC[index - 1] + (s[index - 1] == 'C');
        countG[index] = countG[index - 1] + (s[index - 1] == 'G');
        countT[index] = countT[index - 1] + (s[index - 1] == 'T');
    }
    int numberofA = 0, numberofC = 0, numberofG = 0, numberofT = 0;
    for (int i = 0; i < M; i++)
    {

        numberofA = countA[Q[i] + 1] - countA[p[i]];
        numberofC = countC[Q[i] + 1] - countC[p[i]];
        numberofG = countG[Q[i] + 1] - countG[p[i]];
        numberofT = countT[Q[i] + 1] - countT[p[i]];

        if (numberofA > 0)
            result.push_back(1);
        else if (numberofC > 0)
            result.push_back(2);
        else if (numberofG > 0)
            result.push_back(3);
        else
            result.push_back(4);
    }

    return result;
}
int main()
{
    std::string s = "CAGCCGTA";
    std::vector<int> P = {2, 5, 0};
    std::vector<int> Q = {5, 5, 6};

    for (auto val : solution(s, P, Q))
        std::cout << val << "\t";
    std::cout << std::endl;
}
