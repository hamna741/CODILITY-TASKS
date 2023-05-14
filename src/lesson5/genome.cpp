// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
#include <string>
#include<iostream>
int getImpact(char nucleotide) {
    switch (nucleotide) {
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
std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    int N = S.size();
    std::vector<int> result(P.size());
   std:: vector<std::vector<int>> prefix_sum(N, std::vector<int>(4, 0));
    prefix_sum[0][getImpact(S[0])]++;

    for (int i = 1; i < N; i++) { //for each P-Q range
        prefix_sum[i][0] = prefix_sum[i-1][0];
        prefix_sum[i][1] = prefix_sum[i-1][1];
        prefix_sum[i][2] = prefix_sum[i-1][2];
        prefix_sum[i][3] = prefix_sum[i-1][3];
        prefix_sum[i][getImpact(S[i])]++;
    }

    for (unsigned int i = 0; i < P.size(); i++) {
        int start = P[i];
        int end = Q[i];
        int count =0;
        for (int j = 0; j < 4; j++) {
            if (start>0)
            {
                count=prefix_sum[end][j]-prefix_sum[start-1][j];
                }
            else
                count=prefix_sum[end][j];
            
          
            if (count > 0) {
                result[i] = j + 1;
                break;
            }
        }
    }

    return result;
}