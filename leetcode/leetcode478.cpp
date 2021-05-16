#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double r, x, y;
    // mt19937 rng{random_device{}()};
    // uniform_real_distribution<double> uni{0, 1};
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        double d = r * sqrt((double)rand() / RAND_MAX);
        double theta = (double)rand() / RAND_MAX * 2 * M_PI;
        return {d * cos(theta) + x, d * sin(theta) + y};
    }
};