// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <bitset>
#include <iostream>
int solution(int N)
{
    std::bitset<32> binary(N); // binary representation
    int max_zeros = 0;
    int zero_count = 0;
    bool zero_flag = false;

    for (int i = 0; i < 32; i++)
    {
        if (binary[i])
        { //'1'
            if (zero_flag)
            { // a gap
                max_zeros = std::max(max_zeros, zero_count);
                zero_count = 0; // reset the counter
            }
            else
            {
                zero_flag = true;
            }
        }
        else
        { //'0'
            if (zero_flag)
            {
                zero_count++;
            }
        }
    }
    return max_zeros;
}
int main()
{
    int N = 4625;
    std::cout << solution(N) << std::endl;
}