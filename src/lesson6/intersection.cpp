// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
 #include <algorithm>
 #include<vector>
int solution(std::vector<int> &A) {
     std::vector<int> left(A.size()), right(A.size());
    for (int i = 0; i < A.size(); i++) {
        left[i] = i - A[i];
        right[i] = i + A[i];
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int intersections = 0, circle2 = 0;
    for (int circle1 = 0; circle1 < A.size(); circle1++) {
        while (circle2 < A.size() && right[circle1] >= left[circle2]) {
            intersections += circle2- circle1;
            circle2++;
            if (intersections > 10000000) {
                return -1;
            }
        }
    }
    return intersections;
}
