#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

std::vector<int> divisor(std::vector<int> &vec)
{
    std::vector<int> result;
    int count = 0;
    for (int index = 0; index < vec.size(); index++)
    {
        count = 0;
        for (int index2 = 0; index2 < vec.size(); index2++)
        {
            if (index != index2 && vec[index] % vec[index2] != 0)
                count++;
        }

        result.push_back(count);
    }

    return result;
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout << "INVALID INPUT!!";
        return 1;
    }
    else
    {

        std::vector<int> vec;

        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            vec.push_back(num);
        }
         std::cout<<"NUMBER OF PAIRS: "<<std::endl;
     for(auto val: divisor(vec))
     std::cout<<val;
std::cout<<std::endl;
        //  std::cout<<"NUMBER OF PAIRS: "<<divisor(vec)<<std::endl;
    }
    return 0;
}
