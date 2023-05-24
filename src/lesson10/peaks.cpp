// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>
int solution(std::vector<int> &A)
{
  std::vector<int> peaks;
int g_count=0;
int groups=0;
bool ok;
  for (unsigned int index = 1; index < A.size() - 1; index++)
  {
    if (A[index] > A[index - 1] && A[index] > A[index + 1])
    {
      peaks.push_back(index);
    }
  }

  for (unsigned int size = 1; size <= A.size(); size++)   //peaks =[3 5 10]
  {
    if(peaks.empty())
      break;
    if (A.size() % size != 0)
      continue; // equal size of subarrays
     g_count = 0;
     groups = A.size() / size;
     ok = true;

    for (unsigned int p_index = 0; p_index < peaks.size(); p_index++)
    {

      if (peaks[p_index] / size > g_count)
      {
        ok = false; // peak in diff subarray
        break;
      }
      if (peaks[p_index] / size == g_count)
          g_count++;
      
    }
    if (g_count != groups)
      ok = false;
    if (ok){
      break;
   
    }
  
  }
  return groups;
}

int main()
{
  std::vector<int> A = {1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
  std::cout << solution(A) << std::endl;
}