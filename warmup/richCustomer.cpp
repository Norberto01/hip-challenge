#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rv = 0;
        for (const auto& el: accounts){
            rv = max(rv, accumulate(el.begin(), el.end(), 0));
        }
        return rv;
    }
};