// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>
int solution(int X, int Y, int D) {
 
  int distance = Y - X;
   if (distance % D == 0)
      return distance/D;
   else
      return distance/D + 1;

    }