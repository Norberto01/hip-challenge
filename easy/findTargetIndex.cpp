#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
    public:
        vector<int> targetIndices(vector<int>& nums, int target) {
            int lenNum = nums.size();
            int left = 0;
            int right = lenNum - 1;
            vector<int> rv = {};
            sort(nums.begin(), nums.end());
            int count = 0;
            int mid = left + ((right - left) / 2);
            // cout << "---NM: " << mid;
            while(left <= right) {
                // cout << endl << "*)C("<< count << ") M:" << mid << " | V(M):" << nums.at(mid) << " | T:" << target << " | L:" << left << " | R:" << right << endl;
                if (nums.at(mid) == target) {
                    rv.insert(rv.begin(), mid);
                    int vr = mid-1;
                    if ((vr > 0 && vr < nums.size()) && (nums.at(mid-1) <= target)){
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else if (nums.at(mid) < target) {
                    left = mid + 1;
                }else{
                    left ++;
                    right --;
                }
                mid = left + ((right - left) / 2);
                // cout << "---NM: " << mid;
                count ++;
            }
            sort(rv.begin(), rv.end());
            return rv;
        }
};
int main() {
    // Example usage
    Solution solution;

    vector<int> edgesB = {100, 1, 100}; // {1, 2}
    int target = 100;
    vector<int> rvs = solution.targetIndices(edgesB, target);
    cout << endl << "RV: ----> {";
    for (int i: rvs) {
        cout << i << ", ";
    }
    cout << "}";
    cout << endl << "------------------------------------------------------------------------" << endl;
    vector<int> edgesA = {1, 2, 5, 2, 3}; // {1, 2}
    int targetA = 2;
    vector<int> rvsA = solution.targetIndices(edgesA, targetA);
    cout << endl << "RV: ----> {";
    for (int i: rvsA) {
        cout << i << ", ";
    }
    cout << "}";
}