// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <string>
#include <iostream>
int getImpact(char nucleotide)
{
    switch (nucleotide)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    default:
        return -1;
    }
}
std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q)
{
    //  int N = S.size();
    std::vector<int> result(P.size());
    std::vector<std::vector<int>> prefix_sum(S.size(), std::vector<int>(4, 0));
    prefix_sum[0][getImpact(S[0])]++;

    for (int i = 1; i < S.size(); i++)
    { // for each P-Q range
        prefix_sum[i][0] = prefix_sum[i - 1][0];
        prefix_sum[i][1] = prefix_sum[i - 1][1];
        prefix_sum[i][2] = prefix_sum[i - 1][2];
        prefix_sum[i][3] = prefix_sum[i - 1][3];
        prefix_sum[i][getImpact(S[i])]++;
    }
    for (const auto &row : prefix_sum)
    {
        for (int element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    for (unsigned int i = 0; i < P.size(); i++) // p={2, 5, 0}; q={4, 5, 6};
    {

        int count = 0;
        for (int j = 0; j < 4; j++)
        {

            if (P[i] > 0)
            {
                count = prefix_sum[Q[i]][j] - prefix_sum[P[i] - 1][j];
            }
            else
                count = prefix_sum[Q[i]][j];

            if (count > 0)
            {
                result[i] = j + 1;
                break;
            }
        }
    }

    return result;
}
int main()
{
    std::string s = "CAGCCGTA";
    std::vector<int> P = {2, 5, 0};
    std::vector<int> Q = {5, 5, 6};

    for (auto val : solution(s, P, Q))
        std::cout << val;
}
