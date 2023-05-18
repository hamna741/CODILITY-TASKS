// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
#include <iostream>
int solution(std::vector<int> &A)
{
	if (A.size() == 0)
		return 0;
	if (A.size() == 1)
		return A[0];

	int sum = 0;
	int maximum = A[0];

	for (unsigned int i = 0; i < A.size(); i++)
	{
		A[i] = std::abs(A[i]);
		sum += A[i];
		maximum = std::max(A[i], maximum);
	}
	std::vector<int> count(maximum + 1);

	for (int num : A)
	{

		count[num]++;
	}

	std::vector<int> dp(sum + 1, -1);

	dp[0] = 0;

	for (int i = 0; i <= maximum; i++)
	{
		if (count[i] > 0)
		{ // value is present in A
			for (int val = 0; val <= sum; val++)
			{
				if (dp[val] >= 0)
					dp[val] = count[i];
				else if (val >= i && dp[val - i] > 0)
				{
					dp[val] = dp[val - i] - 1;
				}
			}
		}
	}

	int result = sum;
	for (int i = 0; i <= sum / 2; i++)
	{
		if (dp[i] >= 0)
			result = std::min(result, abs(i - (sum - i)));
	}
	return result;
}
int main()
{
	std::vector<int> A = {1, 5, 2, -2};
	std::cout << solution(A);
}