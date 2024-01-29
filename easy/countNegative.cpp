#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int grid_len = grid.size();
            int left = 0;
            int right = grid_len - 1;
            int neg_grid = 0;
            while (left <= right) {
                vector<int> grid_left = grid.at(left);
                int xleft = 0;
                int xright = grid_left.size() - 1;

                sort(grid_left.begin(), grid_left.end());
                while (xleft <= xright) {
                    int xmid = xleft + ((xright - xleft) / 2);
                    if (grid_left.at(xmid) < 0) {
                        ++neg_grid;
                        ++xleft;
                    } else {
                        --xright;
                    }
                }
                ++left;
            }

            return neg_grid;
        }
};