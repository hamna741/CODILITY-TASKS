#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>

int solitaire( std::vector<int> &vec) {
    
    std::vector<long> max_result(vec.size(), INT_MIN);
    max_result[0] = vec[0];
    for (int index1 = 1; index1 < vec.size(); index1++)
    {
        for (int index2 = 1; index2<7; index2++)
        {
            if (index1 - index2 >= 0) //not to excede 6 
                max_result[index1] = std::max(max_result[index1], vec[index1] + max_result[index1 - index2]);
        }
    }
    return max_result[vec.size() - 1];
}

int main(){
 std::vector<int> vec={1,-2,0,9,-1,-2};
 std::cout<<"MAX SUM= "<<solitaire(vec)<<std::endl;
}

