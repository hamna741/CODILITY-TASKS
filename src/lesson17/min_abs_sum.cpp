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

	std::vector<int> OccurancesOfNum(sum + 1, -1);

	OccurancesOfNum[0] = 0;

	for (int i = 0; i <= maximum; i++)
	{
		if (count[i] > 0)
		{										 // value is present in A
			for (int val = 0; val <= sum; val++) // all possible sums
			{
				if (OccurancesOfNum[val] >= 0)
					OccurancesOfNum[val] = count[i];			   // new value of sum
				else if (val >= i && OccurancesOfNum[val - i] > 0) // OccurancesOfNum[val-i]-->remaining sum
				{
					OccurancesOfNum[val] = OccurancesOfNum[val - i] - 1; //-1 --> one less occurance of i
				}
			}
			for (auto val : OccurancesOfNum)
				std::cout << val;
			std::cout << std::endl;
		}
	}

	int result = sum;
	for (int i = 0; i <= sum / 2; i++)
	{
		if (OccurancesOfNum[i] >= 0)
			result = std::min(result, abs(i - (sum - i)));
	}
	return result;
}
int main()
{
	std::vector<int> A = {1, 5, 2, -2};
	std::cout << solution(A);
}