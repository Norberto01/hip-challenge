#include <vector>

using namespace std;

class Solution {
    public:
        int merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int left = 0;
            int right = m;
            int y = nums2[0];
            
            vector<int> rv = {};
            while(left < right){
                int z = nums1[left];
                rv.push_back(z);
                left ++;
            }

            return rv.size();
        }
};

int main() {
    Solution solution;
 
    vector<int> edg1 = {1,2,3,0,0,0};
    vector<int> edg2 = {2,5,6,9};
    int m = 3;
    int n = 3;
    int rvs = solution.merge(edg1, m, edg2, n);
}